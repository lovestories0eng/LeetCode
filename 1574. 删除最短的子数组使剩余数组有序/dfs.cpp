#include "../stdc++.h"
using namespace std;

// dfs
class Solution {
public:
    int minLength = INT_MAX;
    void dfs(vector<int>& arr, int i, int j, int n) {
        if (i >= j) {
            minLength = 0;
            return;
        }
        if (i < 0 || j > n - 1) {
            if (j - i - 1 < minLength) minLength = j - i - 1;
            return;
        }
        if (j - i - 1 >= minLength) return;
        if (arr[i] <= arr[j]) {
            minLength = j - i - 1;
            return;
        }
        // 前缀剔除最大数
        dfs(arr, i - 1, j, n);
        // 后缀剔除最小数
        dfs(arr, i, j + 1, n);
    }

    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int i, j;
        for (i = 0; i < n - 1; i++) if (arr[i] > arr[i + 1]) break;
        for (j = n - 1; j >= 1; j--) if (arr[j - 1] > arr[j]) break;
        dfs(arr, i, j, n);
        return minLength > 0 ? minLength : 0;
    }
};