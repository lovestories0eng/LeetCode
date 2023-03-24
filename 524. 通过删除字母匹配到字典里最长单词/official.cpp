#include "../stdc++.h"
using namespace std;

class Solution {
public:

    string findLongestWord(string s, vector<string> dictionary) {
        string res = "";
        for (string t : dictionary) {
            int i = 0, j = 0;
            while (i < t.size() && j < s.size()) {
                // 找到所给字符串与 dictionary 中某元素第一个字母相同的位置
                // 贪心取第一个出现的位置可以得到最优解
                if (t[i] == s[j]) {
                    ++i;
                }
                ++j;
            }
            // i 表示字母相等的个数
            if (i == t.size()) {
                if (t.size() > res.size() || (t.size() == res.size() && t.compare(res) < 0)) {
                    res = t;
                }
            }
        }
        return res;
    }
};