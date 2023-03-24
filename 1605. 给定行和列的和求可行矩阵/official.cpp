#include "../stdc++.h"
using namespace std;

// 为什么这样贪心是正确的
/*
    1. 题目保证一定有一个解
    2. rowSum[i]与colSum[j]在遍历过程中一定大于等于0
    3. 如果 rowSum[i] < colSum[j], 则问题转化为 matrix[i + 1 :, j :]的子问题
    4. 如果 rowSum[i] > colSum[j], 则问题转化为 matrix[i :, j + 1 :]的子问题
    5. i == rowLength - 1 && j == colLength - 1时：
        5.1 此时rowSum[i]与colSum[j]都大于等于0
        5.2 由于题目保证有解，因此肯定有解
        5.3 sum(rowSum) == sum(colSum), 每次减去rowSum[i]或者colSum[j]对对总的和影响是相等的, 因此最后一种情况肯定有解
    6. (rowLength + colLength)个方程, (rowLength * colLength)个未知数q, 且(rowLength + colLength) <= (rowLength * colLength)
        6.1 因此只要保证sum(rowSum) == sum(colSum)则一定有解
*/
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int rowLength = rowSum.size(), colLength = colSum.size();
        vector<vector<int>> matrix(rowLength, vector<int>(colLength, 0));
        for (int i = 0, j = 0; i < rowLength && j < colLength;) {
            int rs = rowSum[i], cs = colSum[j];
            matrix[i][j] = min(rs, cs);
            rowSum[i] -= matrix[i][j];
            colSum[j] -= matrix[i][j];
            // 如果行的和更小，那么此行后面的数统统为零
            if (rs < cs) i++;
            // 如果列的和更小，那么此列后面的数统统为零
            else j++;
        }
        return matrix;
    }
};