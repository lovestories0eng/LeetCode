#include "../stdc++.h"
using namespace std;

class Solution {
public:
    string greatestLetter(string s) {
        int lowercase[26] = {0}, uppercase[26] = {0};
        char a = 'a', b = 'z', c = 'A', d = 'Z';
        for (int i = 0; i < s.size(); i++) {
            if ('a' <= s[i] && 'z' >= s[i]) {
                lowercase[s[i] - 'a'] = 1;
            } else if ('A' <= s[i] && 'Z' >= s[i]) {
                uppercase[s[i] - 'A'] = 1;
            }
        }

        for (int i = 0; i < 26; i++) cout << lowercase[i] << " "; cout << endl;
        for (int i = 0; i < 26; i++) cout << uppercase[i] << " "; cout << endl;

        for (int i = 25; i >= 0; i--) {
            if (lowercase[i] && uppercase[i]) {
                return string(1, 'A' + i);
            }
        }
        return "";
    }
};