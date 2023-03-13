#include "../stdc++.h"
using namespace std;

// nums.size = 1300 左右时出现溢出
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        int n = nums.size(), ans = 0;
        map<long long, int> mp;
        long long curProduct = 1;
        mp[1] = -1; mp[0] = -1;
        for (int i = 0; i < n; i++) {
            curProduct *= nums[i];
            if (!mp.count(curProduct))
                mp[curProduct] = i;
            // 找到map中是否存在键大于等于target的值
            long long target = curProduct / k + 1;
            auto it = mp.lower_bound(target);
            if (it != mp.end()) {
                int length = i - it->second;
                ans += length;
            }
        }
        return ans;
    }
};