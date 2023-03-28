#include "../stdc++.h"
using namespace std;

// class Solution {
// public:
//     int countSubstrings(string s, string t) {
//         int m = s.size(), n = t.size();
//         // 设以字符 s[i] 与字符 t[j] 为终点且左侧连续相等的最大长度为 dpl[i][j]，设以字符 s[i] 与字符 t[j] 为终点且右侧连续相等的最大长度为 dpr[i][j]
//         vector<vector<int>> dpl(m + 1, vector<int>(n + 1));
//         vector<vector<int>> dpr(m + 1, vector<int>(n + 1));
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 dpl[i + 1][j + 1] = s[i] == t[j] ? (dpl[i][j] + 1) : 0;
//             }
//         }
//         for (int i = m - 1; i >= 0; i--) {
//             for (int j = n - 1; j >= 0; j--) {
//                 dpr[i][j] = s[i] == t[j] ? (dpr[i + 1][j + 1] + 1) : 0;
//             }
//         }
//         int ans = 0;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 // 因为要求字符串中有一个字符不相等，所以要求 s[i] != t[j]
//                 if (s[i] != t[j]) {
//                     ans += (dpl[i][j] + 1) * (dpr[i + 1][j + 1] + 1);
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int countSubstrings(string s, string t) {
        int m = s.size(), n = t.size();
        // 设以字符 s[i] 与字符 t[j] 为终点且左侧连续相等的最大长度为 dpl[i][j]，设以字符 s[i] 与字符 t[j] 为终点且右侧连续相等的最大长度为 dpr[i][j]
        // 因为索引问题，因此要用一个[m + 1, n + 1]的矩阵
        vector<vector<int>> dpl(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> dpr(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                // dpl[0][0] ~ dpl[0][n] 以及 dp[0][0] ~ dp[m][0]都是初始状态，默认为 0
                // 因为dpl[i][j] = dpl[i − 1][j −1 ] + 1，索引为 0 无法进行状态转移
                // 其实就是因为最初始状态不能构建状态转移方程
                dpl[i + 1][j + 1] = s[i] == t[j] ? (dpl[i][j] + 1) : 0;
        // 另一种写法
        /*
            for (int j = 0; j < m; j++)
                for (int i = 0; i < n; i++)
                    dpl[j + 1][i + 1] = s[j] == t[i] ? (dpl[j][i] + 1) : 0;
        */

        for (int i = m - 1; i >= 0; i--) 
            for (int j = n - 1; j >= 0; j--) 
                // dpl[0][0] ~ dpl[0][n] 以及 dp[0][n] ~ dp[m][n]都是初始状态
                dpr[i][j] = s[i] == t[j] ? (dpr[i + 1][j + 1] + 1) : 0;

        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                // 因为要求字符串中有一个字符不相等，所以要求 s[i] != t[j]
                if (s[i] != t[j])
                    // dpl数组中对应元素坐标都加了 1，dpr数组中对应元素坐标则不变
                    // dpl[i][j]表示不包括当前点的左侧连续相等的最大长度的数组，dpr同理
                    ans += (dpl[i][j] + 1) * (dpr[i + 1][j + 1] + 1);
        return ans;
    }
};