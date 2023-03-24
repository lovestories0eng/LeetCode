#include "../stdc++.h"
using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        // 按照年龄排序
        for (int i = 0; i < n; i++) {
            int k = i;
            for (int j = i + 1; j < n; j++) 
                if (ages[k] > ages[j]) k = j;
            if (k != i) {
                int tmp = ages[i];
                ages[i] = ages[k]; ages[k] = tmp;
                tmp = scores[i];
                scores[i] = scores[k]; scores[k] = tmp;
            }
        }
        // score内部再排序
        for (int i = 0; i < n; i++) {
            int k = i;
            // 如果年龄相同，再按分数升序
            for (int j = i + 1; j < n && ages[i] == ages[j] ; j++) 
                if (scores[k] > scores[j]) k = j;
            if (k != i) {
                int tmp = scores[i];
                scores[i] = scores[k]; scores[k] = tmp;
            }
        }

        int ans = 0;
        // dp[i]表示0~i序列中能选择的最大分数
        int dp[n];
        memset(dp, sizeof(dp), 0);
        for (int i = 0; i < n; i++) {
            int res = 0;
            for (int j = 0; j < i; j++)
                if (scores[i] >= scores[j]) res = max(res, dp[j]);
            dp[i] = res + scores[i], ans = max(ans, dp[i]);
        }
        return ans;
    }
};