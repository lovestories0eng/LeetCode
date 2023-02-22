#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    int secondHighest(string s) {
        bool mp[10] = { false };

        // map<int, bool> mp;
        // for (int i = 0; i < 10; i++) {
        //     mp[i] = false;
        // }
        
        int size = s.size();
        for (int i = 0; i < size; i++) {
            if ('0' <= s[i] && s[i] <= '9') {
                mp[s[i] - '0'] = true;
            }
        }

        bool flag = false;
        for (int i = 9; i >= 0; i--) {
            // 最大的数
            if (!flag) {
                if (mp[i] == true) {
                    flag = true;
                }
            // 次大的数
            } else {
                if (mp[i] == true)
                    return i;
            }
        }
        return -1;
    }
};