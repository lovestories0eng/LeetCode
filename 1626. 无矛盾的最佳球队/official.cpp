#include "../stdc++.h"
using namespace std;

/*
    比较明显的动态规划题。
    首先对数组进行排序，先按年龄升序，如果年龄相同，再按分数升序。（可以构造一个下标数组）
    设 dp[i] 为在球员 1~i 中选出i所能获得的最大分数。状态转移方程如下： dp[i] = max{dp[j]} + score[i]（dp[j]代表序列与i不冲突）
    考虑不冲突的限制：由于是按年龄升序的，这意味着如果要选出球员i，要求 scores[i] 不小于前面选出的每一个。
    而这个约束并不需要刻意维护前面序列的最大值，因为 scores[j] 同样要不小于前面的每一个，所以只要 scores[i] > scores[j]
    上面的 i，j 只是为了表述方便，代码实现中要改成 index[i] 和 index[j]

    PS:为什么所以年龄相同时，要按分数升序排列？可以考虑如下例子：
    (1,3) 与 (1,2) 显然是不冲突的，但如果 (1,3) 排在前，则不可能同时选出这两个球员，因而会出错
*/

class Solution {
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages) {
        int n = ages.size(), ans = 0;
        // 下标数组和 dp 数组
        vector<int> index(n), dp(n, 0);
        // index 赋值为 0 ~ n - 1
        iota(index.begin(), index.end(), 0);
        // 先按年龄升序，再按分数升序进行排序
        sort(
            index.begin(), 
            index.end(), 
            [&](int i, int j) { 
                return ages[i] == ages[j] ? scores[i] < scores[j] : ages[i] < ages[j]; 
            }
        );
        // 递推过程
        for (int i = 0; i < n; ++i) {
            int res = 0;
            for (int j = 0; j < i; ++j)
                // 满足约束，进行保留
                if (scores[index[i]] >= scores[index[j]])
                    res = max(res, dp[j]);
            // 得到 dp[i]，并维护 ans， dp[i] = max{dp[j]} + score[i]
            dp[i] = res + scores[index[i]];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};