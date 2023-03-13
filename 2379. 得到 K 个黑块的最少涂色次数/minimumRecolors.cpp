#include "../stdc++.h"
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        // dp[i]表示第 i 个位置及其之前的所有白色块
        int dp[n + 1];
        for (int i = 0; i < n; i++) {
            dp[i + 1] = blocks[i] == 'W' ? dp[i] + 1 : dp[i];
        }
        int min_k = INT_MAX;
        for (int j = k; j <= n; j++) {
            min_k = min(min_k, dp[j] - dp[j - k]);
        }
        return min_k;
    }
};