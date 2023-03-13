#include "../stdc++.h"
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        // 使用set是为了确保没有相同的元素
        set<int> hashSet;
        for (int num : nums) {
            if (num > 0) {
                hashSet.emplace(num);
            }
        }

        return hashSet.size();
    }
};