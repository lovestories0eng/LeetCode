#include <stdio.h>
#include <pthread.h>
#include "Canvas.c"
#include "GenerateQuestionList.c"

// 正确题数和错误题数
int rightCount = 0;
int wrongCount = 0;
int points = 0;

void generateQuestion(int num, int type);   // 生成题目
void showQuestion(int num, int type);       // 显示题目
char showOption(int num, int type);         // 显示选项
void showAnswer(int num, int type);         // 显示答案
void showCongratulations();                 // 显示恭喜信息

int main() {
    // 初始化时间
    initTime();
    // 创建线程
    pthread_t thread;
    pthread_create(&thread, NULL, (void *)&showTime, NULL);
    // 欢迎页面
    welcome();
    // 显示规则
    showRule();
    // 生成题目列表
    Stack question_stack;
    initQuestion(&question_stack);
//    // 遍历题目栈
//    for (int i = 0; i < 50; i++) {
//        printf("%d %d\n", question_stack.num[i], question_stack.type[i]);
//    }
    points = 0;
    int no = 0;
    // 开始游戏
    // 清屏
    system("cls");
    while (points < 100) {
        // 画布背景
        drawBorder(0, 1, 80, Height);
        gotoxy(3, 2);
        printf("第%d题：\n", no + 1);
        // 从题目栈中取出一道题
        StackNode node = pop(&question_stack);
        generateQuestion(node.num, node.type);
        no++;
        // 清屏
        system("cls");
        if (no == 50) {
            gotoxy(36, Height/2);
            printf("闯关失败——题库都用光了！");
            gotoxy(36, Height/2 + 1);
            printf("游戏结束，您的得分为%d分", points);
            gotoxy(36, Height/2 + 2);
            printf("您一共答对%d题，答错%d题", rightCount, wrongCount);
            gotoxy(36, Height/2 + 3);
            printf("游戏结束，按任意键退出");
            getch();
            exit(0);
        }
    }
    // 结束游戏
    showCongratulations();
    // 结束线程
    pthread_join(thread, NULL);
}

// 游戏逻辑层代码
void generateQuestion(int num, int type) {
    showQuestion(num, type);
    int if_illegal = 0;
    char Answer = showOption(num, type);
    char choice;
    while (if_illegal == 0) {
        choice = getchar();
        if (choice == 'A' || choice == 'a') {
            choice = 'A';
        } else if (choice == 'B' || choice == 'b') {
            choice = 'B';
        } else if (choice == 'C' || choice == 'c') {
            choice = 'C';
        } else if (choice == 'Q' || choice == 'q') {
            // 清屏，重画边框
            system("cls");
            drawBorder(0, 1, 80, Height);
            gotoxy(36, Height/2);
            printf("游戏结束，您的得分为%d分", points);
            gotoxy(36, Height/2 + 1);
            printf("按任意键退出...");
            getchar();
            getchar();
            exit(0);
        } else {
            printf("非法输入，请重新输入！\n");
            continue;
        }
        if_illegal = 1;
    }
    // 清屏，重画边框
    system("cls");
    drawBorder(0, 1, 80, Height);
    if (choice == Answer) {
        gotoxy(36, Height/2);
        printf("答对了！\n");
        rightCount++;
        points += 5;
    } else {
        gotoxy(36, Height/2);
        printf("答错了！\n");
        wrongCount++;
    }
    // 显示答对和答错的数量
    showRightNum(rightCount);
    showWrongNum(wrongCount);
    // 等待用户输入任意键
    gotoxy(36, Height/2 + 1);
    printf("按任意键查看答案...\n");
    getchar();
    getchar();
    // 显示答案和释义
    showAnswer(num, type);
}

void showQuestion(int num, int type) {
    // 显示答对和答错的数量
    showRightNum(rightCount);
    showWrongNum(wrongCount);
    // 在画布上显示题目
    gotoxy(6, 3);
    switch (type) {
        case 1:
            printf("%s", idioms_type1_arr[num].question);
            break;
        case 2:
            printf("%s", idioms_type2_arr[num].explain);
            break;
        default:
            printf("error: unknown type —— 未知的题目类型");
            break;
    }
}

char showOption(int num, int type) {
    char option;
    char *word;
    // 在画布上显示选项
    switch (type) {
        case 1:
            option = idioms_type1_arr[num].answer;
            word = idioms_type1_arr[num].word;
            break;
        case 2:
            option = idioms_type2_arr[num].answer;
            word = idioms_type2_arr[num].word;
            break;
        default:
            printf("error: unknown type —— 未知的题目类型");
            break;
    }
    // 生成两个0到90的随机数
    int random1 = rand() % 90;
    int random2 = rand() % 90;
    // 判断随机数是否重复
    while (random1 == random2) {
        random2 = rand() % 90;
    }
    // 从word_list中随机取成语
    char *wrongAnswer1 = word_list[random1];
    char *wrongAnswer2 = word_list[random2];
    switch (option) {
        case 'A':
            gotoxy(6, 8);
            printf("A. %s", word);
            gotoxy(6, 9);
            printf("B. %s", wrongAnswer1);
            gotoxy(6, 10);
            printf("C. %s", wrongAnswer2);
            break;
        case 'B':
            gotoxy(6, 8);
            printf("A. %s", wrongAnswer1);
            gotoxy(6, 9);
            printf("B. %s", word);
            gotoxy(6, 10);
            printf("C. %s", wrongAnswer2);
            break;
        case 'C':
            gotoxy(6, 8);
            printf("A. %s", wrongAnswer1);
            gotoxy(6, 9);
            printf("B. %s", wrongAnswer2);
            gotoxy(6, 10);
            printf("C. %s", word);
            break;
        default:
            printf("error: unknown option —— 未知的选项");
            break;
    }
    return option;
}

void showAnswer(int num, int type) {
    // 清屏，重画边框
    system("cls");
    drawBorder(0, 1, 80, Height);
    // 在画布上显示答案
    gotoxy(6, 12);
    printf("答案：");
    switch (type) {
        case 1:
            printf("%c ", idioms_type1_arr[num].answer);
            printf("%s", idioms_type1_arr[num].word);
            break;
        case 2:
            printf("%c", idioms_type2_arr[num].answer);
            printf("%s", idioms_type2_arr[num].word);
            break;
        default:
            printf("error: unknown type —— 未知的题目类型");
            break;
    }
    // 在画布上显示释义
    gotoxy(6, 14);
    printf("释义：");
    switch (type) {
        case 1:
            printf("%s", idioms_type1_arr[num].explain);
            break;
        case 2:
            printf("%s", idioms_type2_arr[num].explain);
            break;
        default:
            printf("error: unknown type —— 未知的题目类型");
            break;
    }
    // 显示答对和答错的数量
    showRightNum(rightCount);
    showWrongNum(wrongCount);
    // 显示按任意键继续
    gotoxy(6, Height-2);
    printf("按任意键继续...\n");
    getchar();
}

void showCongratulations() {
    // 清屏，重画边框
    system("cls");
    drawBorder(0, 1, 80, Height);
    // 在画布上显示恭喜
    gotoxy(36, Height/2 - 2);
    printf("恭喜你！闯关成功！\n");
    gotoxy(36, Height/2 - 1);
    printf("你一共答对%d道题，答错%d道题！\n", rightCount, wrongCount);
    gotoxy(36, Height/2);
    printf("本次挑战您的用时为%d秒", timeCount);
    // 显示按任意键继续
    gotoxy(36, Height/2 + 2);
    printf("按任意键退出...\n");
    getchar();
    exit(0);
}
