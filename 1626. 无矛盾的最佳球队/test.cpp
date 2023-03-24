#include <iostream>
#include <algorithm>

int main() {
    int arr1[] = { 3, 1, 4, 2, 5 };
    int arr2[] = { 1, 3, 0, 4, 2 };

    // 使用 lambda 函数作为比较函数
    auto compare = [&arr2](const int& a, const int& b) {
        return arr2[a] < arr2[b];
    };

    std::sort(std::begin(arr1), std::end(arr1), compare);

    // 输出排序后的数组 arr1
    for (const auto& x : arr1) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}


//  g++ -std=c++11 test.cpp -o test  