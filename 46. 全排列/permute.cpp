#include "../stdc++.h"
using namespace std;

class Solution {
public:    
    void backTrack(
        vector<vector<int>>& result, 
        vector<int>& nums, 
        vector<int>& path, 
        vector<bool>& used,
        int& size
    ) {
        if (path.size() == size) {
            result.emplace_back(path);
            return;
        }
        for (int i = 0; i < size; i++) {
            if (!used[i]) {
                used[i] = true;
                path.push_back(nums[i]);
                backTrack(result, nums, path, used, size);
                path.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        int size = nums.size();
        vector<bool> used;
        for (int i = 0; i < size; i++) used.emplace_back(false);
        backTrack(result, nums, path, used, size);

        return result;
    }
};