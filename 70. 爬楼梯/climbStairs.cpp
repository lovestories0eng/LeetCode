#include "../stdc++.h"
using namespace std;

class Solution {
public:
    // 动态规划
    // 第 n 层的种数 = 第 n - 1 层的种数 + 第 n - 2 层的种数
    int climbStairs(int n) {
        int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; ++i) {
            p = q; 
            q = r; 
            r = p + q;
        }
        return r;
    }
};