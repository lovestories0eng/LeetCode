#include<vector>
#include<map>
#include<bits/stdc++>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        map<int, int> indices;
        int n = arr.size();
        for(int i = 0;i < n;i++) {
            indices[arr[i]] = i;
        }
        int ans = 0;
        // n*n的二维数组
        vector<vector<int>> dp(n, vector<int>(n));
        
        // 二维数组初始化为零
        for(int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                dp[i][j] = 0;   
            }
        }
        
        for(int i = 0;i < n;i++) {
            for (int j = i - 1;j >= 0 && arr[j] * 2 > arr[i];j--) {
                int k = -1;
                if(indices.count(arr[i] - arr[j])) {
                    k = indices[arr[i] - arr[j]];
                }
                if (k >= 0) {
                    dp[j][i] = max(dp[k][j] + 1, 3);
                }
                ans = max(dp[j][i], ans);
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}