#include<vector>
#include<map>
#include<algorithm>
using namespace std;

const int N = 55;
int f[N][N][N+N];
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        memset(f, -0x3f, sizeof(f));
        printf("%d ", f[0][0][0]);
        int n = grid.size();
        f[0][0][0] = grid[0][0];
        printf("%d ", f[0][0][0]);
        for(int k = 1; k <= 2 * n - 2; k++){
            for(int i1 = 0; i1 < n && i1 <= k; i1++){
                for(int i2 = 0; i2 < n && i2 <= k; i2++) {
                    int j1 = k - i1;
                    int j2 = k - i2;
                    if(j1 >= 0 && j1 < n && j2 >= 0 && j2 < n) {
                        if(grid[i1][j1] == -1 || grid[i2][j2] == -1) 
                            continue;
                        int t = grid[i1][j1];
                        // ����·�����ཻ����Բȵ�������ݮ
                        if(i1 != i2) t += grid[i2][j2];
                        // ������״̬���Ե��ﵱǰλ��
                        auto x = &f[i1][i2][k];
                        *x = max(*x, f[i1][i2][k-1] + t); // ���� ����
                        if (i2 >= 1)
                            *x = max(*x, f[i1][i2-1][k-1] + t);  //  ���� ����
                        if (i1 >= 1)
                            *x = max(*x, f[i1-1][i2][k-1] + t);  //  ���� ����
                        if (i1 >= 1 && i2 >= 1)
                            *x = max(*x, f[i1-1][i2-1][k-1] + t);        //  ���� ����
                    }
                }
            }
        }
        return max(0, f[n-1][n-1][2*n-2]);
    }
};
int main() {

    return 0;
}