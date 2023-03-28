#include "../stdc++.h"
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        int index = 0, length = 0;
        while(index < n) {
            // 压一个元素进栈
            st.push(pushed[index]);
            index++;
            while(true) {
                // 判断栈顶是否和 poped 数组中需要pop的元素相等，如果一直相等则一直弹栈直到栈为空为止
                if (!st.empty() && st.top() == popped[length]) {
                    st.pop();
                    length++;
                } else break;
            }

        }
        return length == n;
    }
};