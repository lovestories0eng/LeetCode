#include "../stdc++.h"
using namespace std;

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        // 键为前缀和，值为前缀和所对应的索引值
        unordered_map<int, int> indices;
        // 由于空前缀的前缀和是 0 且对应下标 −1，因此首先将前缀和 0 与下标 −1 存入哈希表。
        // 此处考虑的是结果中包含第一个元素的情况
        indices[0] = -1;
        int sum = 0;
        int maxLength = 0;
        int startIndex = -1;
        int n = array.size();
        for (int i = 0; i < n; i++) {
            // sum表示的是当前的前缀和
            if (isalpha(array[i][0])) {
                sum++;
            } else {
                sum--;
            }
            // 查询在之前的数组中是否也有值相同的前缀和，如有则说明存在前缀和为0的情况
            if (indices.count(sum)) {
                int firstIndex = indices[sum];
                // 当前索引减去之前 前缀和相同的索引
                if (i - firstIndex > maxLength) {
                    maxLength = i - firstIndex;
                    // 返回的vector的索引范围为(firstIndex + 1, firstIndex + 1 + maxLength)
                    // 因为前缀和表示的是 firstIndex + maxLength - firstIndex，所以返回结果不包括firstIndex
                    // 因此startIndex需要加一
                    startIndex = firstIndex + 1;
                }
            } else {
                indices[sum] = i;
            }
        }
        if (maxLength == 0) {
            return {};
        }
        return vector<string>(array.begin() + startIndex, array.begin() + startIndex + maxLength);
    }
};