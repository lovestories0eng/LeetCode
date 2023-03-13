#include "../stdc++.h"
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int x = 0;
        for (auto num : nums) {
            x = (x + num) % p;
        }
        if (x == 0) {
            return 0;
        }
        // <键：前缀和 ，值：1值n的和>
        unordered_map<int, int> index;
        int y = 0, res = nums.size();
        int target;
        for (int i = 0; i < nums.size(); i++) {
            // 记录前缀和，如果有多个子数组的前缀和相同，则后面的会覆盖前面的，最终答案得到的还是最小的
            index[y] = i;
            y = (y + nums[i]) % p;
            // 查找目标值，找到前面前缀和为target的子数组
            // 表示的意思是当前和减去多少值后能 mod p
            target = (y - x + p) % p;
            if (index.count(target) > 0) {
                res = min(res, i - index[target] + 1);
            }
        }
        // 如果res没有更新，说明没有找到可以移除的子数组，返回-1
        return res == nums.size() ? -1 : res;
    }
};