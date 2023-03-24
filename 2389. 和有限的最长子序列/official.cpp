#include "../stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        sort(nums.begin(), nums.end());
        vector<int> f(n + 1);
        for (int i = 0; i < n; i++) {
            f[i + 1] = f[i] + nums[i];
        }
        vector<int> answer(m);

        // 由于已经排序了，所以最长子序列一定是从f.begin()开始，直接贪心即可
        for (int i = 0; i < m; i++) {
            answer[i] = upper_bound(f.begin(), f.end(), queries[i]) - f.begin() - 1;
        }
        return answer;
    }
};