#include "../stdc++.h"
using namespace std;

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        set<int> sumSet;
        int tmp;
        for (int i = 0; i < n - 1; i++) {
            tmp = nums[i] + nums[i + 1];
            if (sumSet.count(tmp)) return true;
            else sumSet.insert(tmp);
        }
        return false;
    }
};