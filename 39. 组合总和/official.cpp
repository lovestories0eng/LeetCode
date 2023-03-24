#include "../stdc++.h"
using namespace std;

class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int idx) {
        if (idx == candidates.size()) {
            return;
        }
        if (target == 0) {
            ans.emplace_back(combine);
            return;
        }

        // 选择当前数
        if (target - candidates[idx] >= 0) {
            combine.emplace_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], ans, combine, idx);
            // 向上回溯
            combine.pop_back();
        }

        // 直接跳过
        dfs(candidates, target, ans, combine, idx + 1);

        // target - candidate[idx] < 0 则函数直接返回，向上回溯，因此无需做处理
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        // 先排序，剪枝
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, ans, combine, 0);
        return ans;
    }
};