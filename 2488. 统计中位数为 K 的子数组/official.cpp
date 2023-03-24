#include "../stdc++.h"
using namespace std;

class Solution {
public:
    // 将原始数组做转换，将大于 k 的元素转换成 1，小于 k 的元素转换成 −1，等于 k 的元素转换成 0
    inline int sign(int num) {
        if (num == 0) {
            return 0;
        }
        return num > 0 ? 1 : -1;
    }

    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int kIndex = -1;
        // 找到 k 在原数组的索引值
        for (int i = 0; i < n; i++) {
            if (nums[i] == k) {
                kIndex = i;
                break;
            }
        }
        int ans = 0;
        // counts: 键：前缀和 ，值：数组数量
        unordered_map<int, int> counts;
        // 前缀和为零的情况至少存在一次，就是空数组，为了使得答案可以包括数组的第一个数，如实例[4, 1, 3, 2]
        counts[0] = 1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            // 前缀和，表示当前大于 k 的个数减去小于 k 的个数
            sum += sign(nums[i] - k);
            if (i < kIndex) {
                // 如果键不存在则会返回一个默认值 0
                counts[sum]++;
            } else {
                // 找出之前前缀和为 sum 以及 sum - 1 的情况
                int prev0 = counts[sum];
                int prev1 = counts[sum - 1];
                ans += prev0 + prev1;
            }
        }
        return ans;
    }
};