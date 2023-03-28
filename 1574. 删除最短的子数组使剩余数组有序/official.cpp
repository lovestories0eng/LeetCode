#include "../stdc++.h"
using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), j = n - 1;
        while (j > 0 && arr[j - 1] <= arr[j]) {
            j--;
        }
        if (j == 0) {
            return 0;
        }
        // 初始化答案为 j 前面的元素个数
        int res = j;
        for (int i = 0; i < n; i++) {
            // 找到第一个大于 arr[i] 的 arr[j]
            while (j < n && arr[j] < arr[i]) {
                j++;
            }
            res = min(res, j - i - 1);
            // 如果 arr[i + 1] < arr[i]，说明加入 i + 1后变成了递减的，则直接退出循环
            if (i + 1 < n && arr[i] > arr[i + 1]) {
                break;
            }
        }
        return res;
    }
};