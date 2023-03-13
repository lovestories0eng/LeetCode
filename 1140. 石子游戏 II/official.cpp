#include "../stdc++.h"
using namespace std;

class Solution
{
public:
    int stoneGameII(vector<int> &piles)
    {
        int s = 0, n = piles.size();
        // int f[n][n + 1];
        vector<vector<int>> f(n, vector<int>(n + 1));
        for (int i = n - 1; i >= 0; --i)
        {
            s += piles[i];
            // 假设一直都拿最大的数量，则 m <= i / 2 + 1
            for (int m = 1; m <= i / 2 + 1; ++m)
            {
                // 对手可以拿走所有的石头，收益即为后缀和
                if (i + m * 2 >= n)
                    f[i][m] = s;
                else
                {
                    // mn表示对手能够获得的最高收益，目标是使得对手的最大收益最小
                    int mn = INT_MAX;
                    for (int x = 1; x <= m * 2; ++x)
                        mn = min(mn, f[i + x][max(m, x)]);
                    f[i][m] = s - mn;
                }
            }
        }
        return f[0][1];
    }
};
