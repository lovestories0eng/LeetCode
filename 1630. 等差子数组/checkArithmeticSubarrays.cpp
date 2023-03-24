#include "../stdc++.h"
using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> result;
        vector<int> tmpSequence;
        int n = l.size();
        for (int i = 0; i < n; i++) {
            tmpSequence.assign(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(tmpSequence.begin(), tmpSequence.end());
            int minus = tmpSequence[1] - tmpSequence[0];
            bool flag = true;
            for (int j = 2; j < tmpSequence.size(); j++) {
                if (tmpSequence[j] - tmpSequence[j - 1] != minus) {
                    flag = false;
                    break;
                }
            }
            if (flag) result.emplace_back(true);
            else result.emplace_back(false);
        }
        return result;
    }
};