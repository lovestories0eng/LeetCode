#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = matrix.size();
    std::vector<std::vector<int>> row_prefix_sum(n, std::vector<int>(n)); // 存储每行前缀和的二维数组

    // 计算每行的前缀和
    for (int i = 0; i < n; i++) {
        row_prefix_sum[i][0] = matrix[i][0];
        for (int j = 1; j < n; j++) {
            row_prefix_sum[i][j] = row_prefix_sum[i][j - 1] + matrix[i][j];
        }
    }

    // 计算从i到j每行的和并相加
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int row_sum = 0;
            for (int k = 0; k < n; k++) {
                row_sum += row_prefix_sum[k][j] - (i > 0 ? row_prefix_sum[k][i - 1] : 0);
            }
            sum += row_sum;
        }
    }

    std::cout << "sum = " << sum << std::endl;

    return 0;
}
