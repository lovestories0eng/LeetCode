#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        int matrix[50][50];
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                matrix[i][j] = 0;
            }
        }
        int coordinates = indices.size();
        for(int i=0;i<coordinates;i++) {
            int row = indices[i][0], col = indices[i][1];
            for (int j=0;j<n;j++) {
                matrix[row][j]++;
            }
            for (int i=0;i<m;i++) {
                matrix[i][col]++;
            }
        }
        int ans = 0;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (matrix[i][j] % 2 == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}