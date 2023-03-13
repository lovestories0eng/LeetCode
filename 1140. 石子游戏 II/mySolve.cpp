#include "../stdc++.h"
using namespace std;

class Solution
{
public:
    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();
        // 代表当前的最大收益
        int dp[n][n + 1];

        int suffix_sum = 0;

        // 代表对手可以拿到n-1及其以后的几堆对头（编号从0开始）
        for (int i = n - 1; i >= 0; i--)
        {
            // 后缀和
            suffix_sum += piles[i];
            // 假设一直都拿最大的数量，则当前： m <= i / 2 + 1
            // m 代表当前最多可以拿 2m 堆石头
            for (int m = 1; m <= i / 2 + 1; m++)
            {
                // 当前对手能拿走所有的石头
                if (i + 2 * m >= n) 
                    dp[i][m] = suffix_sum;
                // 当前对手不能拿走所的石头
                else
                {
                    // 对手的最大收益
                    int mn = INT_MAX;
                    for (int x = 1; x <= 2 * m; x++)
                    {
                        // 使得对手的最大收益最小
                        mn = min(mn, dp[i + x][max(m, x)]);
                    }
                    dp[i][m] = suffix_sum - mn;
                }
            }
        }
        return dp[0][1];
    }
};