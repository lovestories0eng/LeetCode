#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

class Solution {
public:
    int evaluate(string expression) {
        int nowIndex = 1;//����������ַ����±꣬��ʼ��Ϊ1����Ϊÿ�����붼��һ���������
        unordered_map<string, int> hashMap;//���ڴ���������ʽ��let��ֵ����
        return myEvaluate(expression, nowIndex, hashMap);//��ʼ����һ��expression
    }
    //��ʼ������nowIndexΪ��ʼ��һ��expression
    int myEvaluate(string &expression, int &nowIndex, unordered_map<string, int> hashMap){
        if (expression[nowIndex] == 'a'){
            //��һ�����������add����
            int firstNum = 0, secondNum = 0;
            nowIndex += 4;//����"add "
            //��һ������add�ĵ�һ�����ʽ������ֵ
            if (expression[nowIndex] == '('){//��һ�����ʽҲ��"(...)"���ݹ鴦��
                nowIndex += 1;//����������
                firstNum = myEvaluate(expression, nowIndex, hashMap);
            }
            else{//����������ʽ�Ǳ������߳��������ʽֻ�����ֿ��ܣ�
                firstNum = myFunc(expression, nowIndex, hashMap);
            }
            nowIndex += 1;//�����ո�
            //�ڶ�������add�ĵڶ������ʽ������ֵ
            if (expression[nowIndex] == '('){//�ڶ������ʽҲ��"(...)"���ݹ鴦��
                nowIndex += 1;//����������
                secondNum = myEvaluate(expression, nowIndex, hashMap);
            }
            else{//����������ʽ�Ǳ������߳��������ʽֻ�����ֿ��ܣ�
                secondNum = myFunc(expression, nowIndex, hashMap);
            }
            nowIndex += 1;//����������
            return firstNum + secondNum;//���мӷ�����
        }
        else if (expression[nowIndex] == 'm'){
            //�ڶ������������mult����
            int firstNum = 0, secondNum = 0;
            nowIndex += 5;//����"mult "
            //��һ������mult�ĵ�һ�����ʽ������ֵ
            if (expression[nowIndex] == '('){//��һ�����ʽҲ��"(...)"���ݹ鴦��
                nowIndex += 1;//����������
                firstNum = myEvaluate(expression, nowIndex, hashMap);
            }
            else{//����������ʽ�Ǳ������߳��������ʽֻ�����ֿ��ܣ�
                firstNum = myFunc(expression, nowIndex, hashMap);
            }
            nowIndex += 1;//�����ո�
            //�ڶ�������mult�ĵڶ������ʽ������ֵ
            if (expression[nowIndex] == '('){//�ڶ������ʽҲ��"(...)"���ݹ鴦��
                nowIndex += 1;//����������
                secondNum = myEvaluate(expression, nowIndex, hashMap);
            }
            else{//����������ʽ�Ǳ������߳��������ʽֻ�����ֿ��ܣ�
                secondNum = myFunc(expression, nowIndex, hashMap);
            }
            nowIndex += 1;//����������
            return firstNum * secondNum;//���г˷�����
        }
        else {
            //���������������let����(let v1 e1 v2 e2 ... vn en expr)
            //����ÿ�γɶԽ��д���v1 e1��,��v2��e2��,��v3��e3��, ... , ��v n - 1��e n - 1��,��v n��e n������󵥳�expr
            nowIndex += 4;//����"let "
            while (true){
                if (expression[nowIndex] == '('){
                    //let�е�exprҲ��һ��"(...)"���ݹ鴦��
                    nowIndex += 1;
                    int tempRes = myEvaluate(expression, nowIndex, hashMap);
                    nowIndex += 1;//����������
                    return tempRes;
                }
                //���潫��ÿ�δ���һ������һ�����ʽ
                string str = "";
                while (expression[nowIndex] != ')' && expression[nowIndex] != ' '){
                    str += expression[nowIndex++];
                }
                if (expression[nowIndex] == ')'){
                    //�����������ţ���˵�����һ��expr���ʽ�ǳ������߱���
                    nowIndex += 1;
                    if (hashMap.count(str)){
                        return hashMap[str];
                    }
                    else{
                        return atoi(str.c_str());
                    }
                }
                else{
                    //�����ȡһ��(���� ���ʽ)���и�ֵ����
                    nowIndex += 1;
                    if (expression[nowIndex] == '('){//e n���ʽҲ��"(...)"���ݹ鴦��
                        nowIndex += 1;//����������
                        hashMap[str] = myEvaluate(expression, nowIndex, hashMap);
                    }
                    else{//e n���ʽ�Ǳ������߳��������ʽֻ�����ֿ��ܣ�
                        hashMap[str] = myFunc(expression, nowIndex, hashMap);
                    }
                    nowIndex += 1;
                }
            }
        }
    }
    //��ȡnowIndexΪ��ʼ�±��һ�����ʽ��������ʽ�ǳ�������2��������һ����hashMap�еı�����
    int myFunc(string &expression, int &nowIndex, unordered_map<string, int> &hashMap){
        string str = "";
        while (expression[nowIndex] != ' ' && expression[nowIndex] != ')'){
            str += expression[nowIndex++];
        }
        if (hashMap.count(str)){//��һ����hashMap�еı���
            return hashMap[str];
        }
        else{//���ʽ�ǳ�������2
            return atoi(str.c_str());
        }
    }
};
