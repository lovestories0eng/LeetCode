#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

class Solution {
public:
    int evaluate(string expression) {
        // 即将处理的字符串下标，初始化为1，因为每个输入都有一个外加括号
        int nowIndex = 1;
        // 用于存储这个表达式中let赋值操作
        unordered_map<string, int> hashMap;
        return myEvaluate(expression, nowIndex, hashMap);
    }
    int myEvaluate(string &expression, int &nowIndex, unordered_map<string, int> hashMap) {
        // 第一种情况：处理add操作
        if (expression[nowIndex] == 'a') {
            int firstNum = 0, secondNum = 0;
            // 跳过“add ”
            nowIndex += 4;
            // 第一步：求add的第一个表达式参数的值
            if (expression[nowIndex] == '(') {// 如果第一个表达式也是“(...)”，递归处理
                nowIndex += 1;
                firstNum = myEvaluate(expression, nowIndex, hashMap);
            }
            else {// 否则这个表达式是变量或者常量（表达式只有三种可能）
                firstNum = myFunc(expression, nowIndex, hashMap);
            }
            // 跳过空格
            nowIndex += 1;
            // 第二步：求add的第二个表达式参数的值
            if (expression[nowIndex] == '(') {// 第二个表达式也是“(...)”，递归处理
                nowIndex += 1;
                secondNum = myEvaluate(expression, nowIndex, hashMap);
            }
            else { // 否则这个表达式是变量或者常量（表达式只有三种可能）
                secondNum = myFunc(expression, nowIndex, hashMap);
            }
            nowIndex += 1;
            return firstNum + secondNum;
        }
        else if (expression[nowIndex] == 'm') {
            // 第二种情况，处理mult操作
            int firstNum = 0, secondNum = 0;
            // 跳过“mult ”
            nowIndex += 5;
            // 第一步，求mult的第一个表达式参数的值
            if (expression[nowIndex] == '(') {// 第一个表达式的值也是“(...)”，递归处理
                //跳过左括号
                nowIndex += 1;
                firstNum = myEvaluate(expression, nowIndex, hashMap);
            }
            else {// 否则这个表达式是变量或者常量（表达式只有三种可能）
                firstNum = myFunc(expression, nowIndex, hashMap);
            }
            // 跳过空格
            nowIndex += 1;
            // 第二步，求mult的第二个表达式参数的值
            if (expression[nowIndex] == '(') {// 第二个表达式的值也是“(...)”，递归处理
                //跳过左括号
                nowIndex += 1;
                secondNum = myEvaluate(expression, nowIndex, hashMap);
            }
            else {// 否则这个表达式是变量或者常量（表达式只有三种可能）
                secondNum = myFunc(expression, nowIndex, hashMap);
            }
            // 跳过右括号
            nowIndex += 1;
            return firstNum * secondNum;
        }
        // 第三种情况，处理let
        else {
            // 跳过“let ”
            nowIndex += 4;
            while(true) {
                // 每次处理一个变量一个表达式
                string str = "";
                while (expression[nowIndex] != ')' && expression[nowIndex] != ' ') {
                    str += expression[nowIndex++];
                }
                if(expression[nowIndex] == ')') {
                    //遇到了右括号，则说明最后一个expr是常量或者变量
                    nowIndex += 1;
                    if(hashMap.count(str)) {
                        return hashMap[str];
                    }
                    else {
                        return atoi(str.c_str());
                    }
                }
                else {
                    // 否则读取一个变量（表达式）进行赋值操作
                    nowIndex += 1;
                    if (expression[nowIndex] == '(') {// e, n表达式也是“(...)”，递归处理
                        // 跳过右括号
                        nowIndex += 1;
                        hashMap[str] = myEvaluate(expression, nowIndex, hashMap);
                    }
                    else {// e, n表达式是变量或者常量（表达式只有三种可能）
                        hashMap[str] = myFunc(expression, nowIndex, hashMap);
                    }
                    nowIndex += 1;
                }
                // let中的expr也是一个“(...)”，递归处理，因为如果是变量是不可能为'('的
                if(expression[nowIndex] == '(') {
                    // 跳过左括号
                    nowIndex += 1;
                    int tempRes = myEvaluate(expression, nowIndex, hashMap);
                    // 跳过右括号
                    nowIndex += 1;
                    return tempRes;
                }
            }
        }
    }
    int myFunc(string &expression, int &nowIndex, unordered_map<string, int> &hashMap) {
        string str = "";
        while(expression[nowIndex] != ' ' && expression[nowIndex] != ')') {
            str += expression[nowIndex++];
        }
        // 如果str是一个再hashMap中的变量
        if (hashMap.count(str)) {
            return hashMap[str];
        }
        // 如果str不是变量则只能是常量
        else {
            return atoi(str.c_str());
        }
    }
};