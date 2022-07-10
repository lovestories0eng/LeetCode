#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

class Solution {
public:
    int evaluate(string expression) {
        int nowIndex = 1;
        unordered_map<string, int> hashMap;
        return myEvaluate(expression, nowIndex, hashMap);
    }
    int myEvaluate(string &expression, int &nowIndex, unordered_map<string, int> hashMap) {
        if (expression[nowIndex] == 'a') {
            int firstNum = 0, secondNum = 0;
            nowIndex += 4;
            if (expression[nowIndex] == '(') {
                nowIndex += 1;
                firstNum = myEvaluate(expression, nowIndex, hashMap);
            }
            else {
                firstNum = myFunc(expression, nowIndex, hashMap);
            }
            nowIndex += 1;
            if (expression[nowIndex] == '(') {
                nowIndex += 1;
                secondNum = myEvaluate(expression, nowIndex, hashMap);
            }
            else {
                secondNum = myFunc(expression, nowIndex, hashMap);
            }
            nowIndex += 1;
            return firstNum + secondNum;
        }
        else if (expression[nowIndex] == 'm') {
            int firstNum = 0, secondNum = 0;
            nowIndex += 5;
            if (expression[nowIndex] == '(') {
                nowIndex += 1;
                firstNum = myEvaluate(expression, nowIndex, hashMap);
            }
            else {
                firstNum = myFunc(expression, nowIndex, hashMap);
            }
            nowIndex += 1;
            if (expression[nowIndex] == '(') {
                nowIndex += 1;
                secondNum = myEvaluate(expression, nowIndex, hashMap);
            }
            else {
                secondNum = myFunc(expression, nowIndex, hashMap);
            }
            nowIndex += 1;
            return firstNum * secondNum;
        }
        else {
            nowIndex += 4;
            while(true) {
                if(expression[nowIndex] == '(') {
                    nowIndex += 1;
                    int tempRes = myEvaluate(expression, nowIndex, hashMap);
                    nowIndex += 1;
                    return tempRes;
                }
                string str = "";
                while (expression[nowIndex] != ')' && expression[nowIndex] != ' ') {
                    str += expression[nowIndex++];
                }
                if(expression[nowIndex] == ')') {
                    nowIndex += 1;
                    if(hashMap.count(str)) {
                        return hashMap[str];
                    }
                    else {
                        return atoi(str.c_str());
                    }
                }
                else {
                    nowIndex += 1;
                    if (expression[nowIndex] == '(') {
                        nowIndex += 1;
                        hashMap[str] = myEvaluate(expression, nowIndex, hashMap);
                    }
                    else {
                        hashMap[str] = myFunc(expression, nowIndex, hashMap);
                    }
                    nowIndex += 1;
                }
            }
        }
    }
    int myFunc(string &expression, int &nowIndex, unordered_map<string, int> &hashMap) {
        string str = "";
        while(expression[nowIndex] != ' ' && expression[nowIndex] != ')') {
            str += expression[nowIndex++];
        }
        if (hashMap.count(str)) {
            return hashMap[str];
        }
        else {
            return atoi(str.c_str());
        }
    }
};