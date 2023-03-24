#include "../stdc++.h"
using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool> ans;
        for (int i = 0; i < n; i++) {
            int left = l[i], right = r[i];
            // 当前子数组的最小值
            int minv = *min_element(nums.begin() + left, nums.begin() + right + 1);
            // 当前子数组的最大值
            int maxv = *max_element(nums.begin() + left, nums.begin() + right + 1);

            if (minv == maxv) {
                ans.push_back(true);
                continue;
            }
            // (最大数 - 最小数) / 区间长度 如果不是一个整数，则肯定不是等差数列
            if ((maxv - minv) % (right - left) != 0) {
                ans.push_back(false);
                continue;
            }

            // 当前
            int d = (maxv - minv) / (right - left);
            bool flag = true;
            // 记录当前子数组的被访问过的数
            vector<int> seen(right - left + 1);
            for (int j = left; j <= right; j++) {
                if ((nums[j] - minv) % d != 0) {
                    flag = false;
                    break;
                }
                int t = (nums[j] - minv) / d;
                // 一个等差数列中不可能有两个相等的数，如果有则肯定不是等差数列
                if (seen[t]) {
                    flag = false;
                    break;
                }
                seen[t] = true;
            }
            ans.push_back(flag);
        }
        return ans;
    }
};