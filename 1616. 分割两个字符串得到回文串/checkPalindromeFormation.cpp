#include "../stdc++.h"
using namespace std;

int judge(string str) {
    int n = str.size();
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - 1 - i]) return 0;
    }
    return 1;
}

// 数据量为5300左右时会超时
class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        int n = a.size();

        for (int i = 0; i < n; i++) {
            string tmp1 = a.substr(0, i) + b.substr(i, n - i);




            string tmp2 = b.substr(0, i) + a.substr(i, n - i);
            if (judge(tmp1) || judge(tmp2)) return true;
        }
        return false;
    }
};