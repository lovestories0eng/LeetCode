#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

class Solution {
public:
    int evaluate(string expression) {
        // ����������ַ����±꣬��ʼ��Ϊ1����Ϊÿ�����붼��һ���������
        int nowIndex = 1;
        // ���ڴ洢������ʽ��let��ֵ����
        unordered_map<string, int> hashMap;
        return myEvaluate(expression, nowIndex, hashMap);
    }
    int myEvaluate(string &expression, int &nowIndex, unordered_map<string, int> hashMap) {
        // ��һ�����������add����
        if (expression[nowIndex] == 'a') {
            int firstNum = 0, secondNum = 0;
            // ������add ��
            nowIndex += 4;
            // ��һ������add�ĵ�һ�����ʽ������ֵ
            if (expression[nowIndex] == '(') {// �����һ�����ʽҲ�ǡ�(...)�����ݹ鴦��
                nowIndex += 1;
                firstNum = myEvaluate(expression, nowIndex, hashMap);
            }
            else {// ����������ʽ�Ǳ������߳��������ʽֻ�����ֿ��ܣ�
                firstNum = myFunc(expression, nowIndex, hashMap);
            }
            // �����ո�
            nowIndex += 1;
            // �ڶ�������add�ĵڶ������ʽ������ֵ
            if (expression[nowIndex] == '(') {// �ڶ������ʽҲ�ǡ�(...)�����ݹ鴦��
                nowIndex += 1;
                secondNum = myEvaluate(expression, nowIndex, hashMap);
            }
            else { // ����������ʽ�Ǳ������߳��������ʽֻ�����ֿ��ܣ�
                secondNum = myFunc(expression, nowIndex, hashMap);
            }
            nowIndex += 1;
            return firstNum + secondNum;
        }
        else if (expression[nowIndex] == 'm') {
            // �ڶ������������mult����
            int firstNum = 0, secondNum = 0;
            // ������mult ��
            nowIndex += 5;
            // ��һ������mult�ĵ�һ�����ʽ������ֵ
            if (expression[nowIndex] == '(') {// ��һ�����ʽ��ֵҲ�ǡ�(...)�����ݹ鴦��
                //����������
                nowIndex += 1;
                firstNum = myEvaluate(expression, nowIndex, hashMap);
            }
            else {// ����������ʽ�Ǳ������߳��������ʽֻ�����ֿ��ܣ�
                firstNum = myFunc(expression, nowIndex, hashMap);
            }
            // �����ո�
            nowIndex += 1;
            // �ڶ�������mult�ĵڶ������ʽ������ֵ
            if (expression[nowIndex] == '(') {// �ڶ������ʽ��ֵҲ�ǡ�(...)�����ݹ鴦��
                //����������
                nowIndex += 1;
                secondNum = myEvaluate(expression, nowIndex, hashMap);
            }
            else {// ����������ʽ�Ǳ������߳��������ʽֻ�����ֿ��ܣ�
                secondNum = myFunc(expression, nowIndex, hashMap);
            }
            // ����������
            nowIndex += 1;
            return firstNum * secondNum;
        }
        // ���������������let
        else {
            // ������let ��
            nowIndex += 4;
            while(true) {
                // ÿ�δ���һ������һ�����ʽ
                string str = "";
                while (expression[nowIndex] != ')' && expression[nowIndex] != ' ') {
                    str += expression[nowIndex++];
                }
                if(expression[nowIndex] == ')') {
                    //�����������ţ���˵�����һ��expr�ǳ������߱���
                    nowIndex += 1;
                    if(hashMap.count(str)) {
                        return hashMap[str];
                    }
                    else {
                        return atoi(str.c_str());
                    }
                }
                else {
                    // �����ȡһ�����������ʽ�����и�ֵ����
                    nowIndex += 1;
                    if (expression[nowIndex] == '(') {// e, n���ʽҲ�ǡ�(...)�����ݹ鴦��
                        // ����������
                        nowIndex += 1;
                        hashMap[str] = myEvaluate(expression, nowIndex, hashMap);
                    }
                    else {// e, n���ʽ�Ǳ������߳��������ʽֻ�����ֿ��ܣ�
                        hashMap[str] = myFunc(expression, nowIndex, hashMap);
                    }
                    nowIndex += 1;
                }
                // let�е�exprҲ��һ����(...)�����ݹ鴦����Ϊ����Ǳ����ǲ�����Ϊ'('��
                if(expression[nowIndex] == '(') {
                    // ����������
                    nowIndex += 1;
                    int tempRes = myEvaluate(expression, nowIndex, hashMap);
                    // ����������
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
        // ���str��һ����hashMap�еı���
        if (hashMap.count(str)) {
            return hashMap[str];
        }
        // ���str���Ǳ�����ֻ���ǳ���
        else {
            return atoi(str.c_str());
        }
    }
};