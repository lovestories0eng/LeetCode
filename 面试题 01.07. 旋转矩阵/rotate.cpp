#include "../stdc++.h"
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 先以1、5、9为对角线对称然后每行反序一下
        // 1 -> 0, 2 -> 1, (3 -> 1), 4 -> 1, 5 -> 0
        // 1 -> 0, 2 -> 1, 3 -> 1, (4 -> 2), 5 -> 1, 6 -> 1, 7 -> 0
        int n = matrix.size();
        for (int i = 1; i <= 2 * n - 1; i++) {
            // x坐标与y坐标
            int x = i <= n ? i - 1 : n - 1;
            int y = i <= n ? 0 : i - n;
            while(x > y) {
                int temp1 = matrix[y][x];
                matrix[y][x] = matrix[x][y];
                matrix[x][y] = temp1;
                x--; y++;
            }
        }
        // 使得每一列都反序
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};