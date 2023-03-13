#include "../stdc++.h"
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        // 纵坐标范围
        int a = grid.size();
        // 横坐标范围
        int b = grid[0].size();
        int dp[a][b];
        memset(dp, 0, sizeof(dp));
        // i: 纵坐标
        // j: 横坐标
        for (int i = a - 1; i >= 0; i--) {
            for (int j = b - 1; j >= 0; j--) {
                if (i == a - 1 && j == b - 1)
                    dp[i][j] = grid[i][j];
                else {
                    // 横坐标不越界而纵坐标越界
                    if (i + 1 < a && j + 1 == b)
                        dp[i][j] = grid[i][j] + dp[i + 1][j];
                    // 横坐标越界而纵坐标不越界
                    else if (i + 1 == a && j + 1 < b)
                        dp[i][j] = grid[i][j] + dp[i][j + 1];
                    // 横坐标和纵坐标都不越界
                    else
                        dp[i][j] = grid[i][j] + max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[0][0];
    }
};