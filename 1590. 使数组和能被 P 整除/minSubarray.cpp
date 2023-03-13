#include "../stdc++.h"
using namespace std;

// 内存溢出，空间复杂度为O(n^2)
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        // 存储从 i 到 j 的前缀和
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        // 数组元素和
        int sum = 0;
        int min_to_del = INT_MAX;
        for (int i = 0; i < n; i++) {
            sum += nums[i] % p;
        }
        // 需要减去del值才能够被p整除
        int del = sum % p;
        if (del == 0) return 0;

        for (int i = 0; i < n; i++) {
            int suffix_sum = 0;
            for (int j = i; j < n; j++) {
                suffix_sum += nums[j];
                dp[i][j] = suffix_sum;
            }
        }

        for (int i = 0; i < n - 1; i++) {
            // cout << dp[0][i] << " " << del << endl;
            if ((dp[0][i] - del) % p == 0)
                min_to_del = i + 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if ((dp[i][j] - dp[i][i] - del) % p == 0) {
                    if (j - i < min_to_del)
                        min_to_del = j - i;
                }
            }
        }

        if (min_to_del == INT_MAX) min_to_del = -1;
        return min_to_del;
    }
};