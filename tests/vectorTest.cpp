#include <vector>
#include <iostream>

int main() {
    std::vector<int> myVector; // 声明一个空的vector对象
    // 向vector中添加元素
    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);
    // 输出vector中的元素
    for (int i = 0; i < myVector.size(); i++) {
        std::cout << myVector[i] << " ";
    }
    return 0;
}
