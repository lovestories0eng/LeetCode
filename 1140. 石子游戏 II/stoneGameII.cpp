#include "../stdc++.h"
using namespace std;

class Solution
{
public:
    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();
        // dfs(i,m) 表示前 i 堆石头已经被取走，当前的 M=m 的情况下，接下去取石头的玩家可以比另一方多取的石头数
        int dp[n + 1][n + 1];

        int suffixSum[n][n];

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int tmp = 0;
                for (int k = i; k <= j; k++)
                {
                    tmp += piles[k];
                }
                suffixSum[i][j] = tmp;
            }
        }

        // i代表当前已经取走了前i堆
        for (int i = n; i >= 0; i--)
        {
            // TODO：提升sum的作用域名
            for (int m = 1; m <= n && m + i <= n + 1; m++)
            {
                if (i == n)
                {
                    dp[i][m] = 0;
                }
                else
                {
                    for (int x = 1; x <= 2 * m; x++)
                    {
                        if (i + x > n)
                            break;
                        // 接下来比对方多取的石头数 = max(接下来比对方多取的石头数，当前选择的石头数 - 接下来对手比我们多取的石头数)
                        // 要多次比较，因为在for循环中
                        dp[i][m] = max(dp[i][m], suffixSum[i][i + x - 1] - dp[i + x][min((n - i - x + 1), max(m, x))]);
                    }
                }
            }
        }
        return (dp[0][1] + suffixSum[0][n - 1]) / 2;
    }
};