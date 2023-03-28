#include "../stdc++.h"
using namespace std;

// 贪心，114/118
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int i, j;
        for (i = 0; i < n - 1; i++)
            if (arr[i] > arr[i + 1]) break;
        for (j = n - 1; j >= 1; j--)
            if (arr[j - 1] > arr[j]) break;

        int prefix = 0, suffix = 0;
        // 使得后缀的第一个数大于前缀的最后一个数
        int _t;
        for (_t = j; _t < n; _t++)
            if (arr[_t] >= arr[i]) break;
        prefix = _t - i - 1;
        for (_t = i; _t >= 0; _t--)
            if (arr[_t] <= arr[j]) break;
        suffix = j - _t - 1;
        return min(prefix, suffix) > 0 ? min(prefix, suffix) : 0;
    }
};