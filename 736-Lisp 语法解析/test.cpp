#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

class Solution {
public:
    int evaluate(string expression) {
        int nowIndex = 1;//即将处理的字符串下标，初始化为1，因为每个输入都有一个外加括号
        unordered_map<string, int> hashMap;//用于储存这个表达式中let赋值操作
        return myEvaluate(expression, nowIndex, hashMap);//开始处理一个expression
    }
    //开始处理以nowIndex为起始的一个expression
    int myEvaluate(string &expression, int &nowIndex, unordered_map<string, int> hashMap){
        if (expression[nowIndex] == 'a'){
            //第一种情况：处理add操作
            int firstNum = 0, secondNum = 0;
            nowIndex += 4;//跳过"add "
            //第一步：求add的第一个表达式参数的值
            if (expression[nowIndex] == '('){//第一个表达式也是"(...)"，递归处理
                nowIndex += 1;//跳过左括号
                firstNum = myEvaluate(expression, nowIndex, hashMap);
            }
            else{//否则这个表达式是变量或者常量（表达式只有三种可能）
                firstNum = myFunc(expression, nowIndex, hashMap);
            }
            nowIndex += 1;//跳过空格
            //第二步：求add的第二个表达式参数的值
            if (expression[nowIndex] == '('){//第二个表达式也是"(...)"，递归处理
                nowIndex += 1;//跳过左括号
                secondNum = myEvaluate(expression, nowIndex, hashMap);
            }
            else{//否则这个表达式是变量或者常量（表达式只有三种可能）
                secondNum = myFunc(expression, nowIndex, hashMap);
            }
            nowIndex += 1;//跳过右括号
            return firstNum + secondNum;//进行加法操作
        }
        else if (expression[nowIndex] == 'm'){
            //第二种情况：处理mult操作
            int firstNum = 0, secondNum = 0;
            nowIndex += 5;//跳过"mult "
            //第一步：求mult的第一个表达式参数的值
            if (expression[nowIndex] == '('){//第一个表达式也是"(...)"，递归处理
                nowIndex += 1;//跳过左括号
                firstNum = myEvaluate(expression, nowIndex, hashMap);
            }
            else{//否则这个表达式是变量或者常量（表达式只有三种可能）
                firstNum = myFunc(expression, nowIndex, hashMap);
            }
            nowIndex += 1;//跳过空格
            //第二步：求mult的第二个表达式参数的值
            if (expression[nowIndex] == '('){//第二个表达式也是"(...)"，递归处理
                nowIndex += 1;//跳过左括号
                secondNum = myEvaluate(expression, nowIndex, hashMap);
            }
            else{//否则这个表达式是变量或者常量（表达式只有三种可能）
                secondNum = myFunc(expression, nowIndex, hashMap);
            }
            nowIndex += 1;//跳过右括号
            return firstNum * secondNum;//进行乘法操作
        }
        else {
            //第三种情况：处理let操作(let v1 e1 v2 e2 ... vn en expr)
            //我们每次成对进行处理（v1 e1）,（v2，e2）,（v3，e3）, ... , （v n - 1，e n - 1）,（v n，e n），最后单出expr
            nowIndex += 4;//跳过"let "
            while (true){
                if (expression[nowIndex] == '('){
                    //let中的expr也是一个"(...)"，递归处理
                    nowIndex += 1;
                    int tempRes = myEvaluate(expression, nowIndex, hashMap);
                    nowIndex += 1;//跳过右括号
                    return tempRes;
                }
                //下面将会每次处理一个变量一个表达式
                string str = "";
                while (expression[nowIndex] != ')' && expression[nowIndex] != ' '){
                    str += expression[nowIndex++];
                }
                if (expression[nowIndex] == ')'){
                    //遇到了右括号，则说明最后一个expr表达式是常量或者变量
                    nowIndex += 1;
                    if (hashMap.count(str)){
                        return hashMap[str];
                    }
                    else{
                        return atoi(str.c_str());
                    }
                }
                else{
                    //否则读取一个(变量 表达式)进行赋值操作
                    nowIndex += 1;
                    if (expression[nowIndex] == '('){//e n表达式也是"(...)"，递归处理
                        nowIndex += 1;//跳过右括号
                        hashMap[str] = myEvaluate(expression, nowIndex, hashMap);
                    }
                    else{//e n表达式是变量或者常量（表达式只有三种可能）
                        hashMap[str] = myFunc(expression, nowIndex, hashMap);
                    }
                    nowIndex += 1;
                }
            }
        }
    }
    //读取nowIndex为起始下标的一个表达式（这个表达式是常量比如2，或者是一个在hashMap中的变量）
    int myFunc(string &expression, int &nowIndex, unordered_map<string, int> &hashMap){
        string str = "";
        while (expression[nowIndex] != ' ' && expression[nowIndex] != ')'){
            str += expression[nowIndex++];
        }
        if (hashMap.count(str)){//是一个在hashMap中的变量
            return hashMap[str];
        }
        else{//表达式是常量比如2
            return atoi(str.c_str());
        }
    }
};
