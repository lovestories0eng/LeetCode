#include "../stdc++.h"
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        int res = 0, pre_add = INT_MAX;
        for(auto n : nums){
            if(n == 0) break;
            if(n < pre_add){
                pre_add = n;
                res++;
            }
        }
        return res;
    }
};