#include "../stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        sort(nums.begin(), nums.end());
        map<int, int> mp;

        vector<int> result(m, INT_MIN);
        int sum = 0;
        mp[sum] = -1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            mp[sum] = i;
            for (int j = 0; j < m; j++) {
                int tmp = sum - queries[j];
                int it = mp.lower_bound(tmp)->second;
                if (i - it > result[j]) result[j] = i - it;
            }
        }
        return result;
    }
};