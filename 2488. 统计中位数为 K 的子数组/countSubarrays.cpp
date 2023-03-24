#include "../stdc++.h"
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        auto it = find(nums.begin(), nums.end(), k);
        int index = distance(nums.begin(), it);
        // cout << index << endl;

        // 记录数组该位置的值比 k 大还是比 k 小
        vector<int> cache(n, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] > k) cache[i] = 2;
            else cache[i] = 1;
        }

        int result = 0;
        // 向左
        for (int i = index; i >= 0; i--) {
            // 向右
            for (int j = index; j < n; j++) {
                // 分别记录比 k 大的数量和比 k 小的数量
                int big = 0, small = 0;
                for (int x = i; x <= j; x++) {
                    if (cache[x] == 2) big += 1;
                    else if (cache[x] == 1) small += 1;
                }
                if (small == big || small == big + 1) result += 1;
            }
        }
        return result;
    }
};