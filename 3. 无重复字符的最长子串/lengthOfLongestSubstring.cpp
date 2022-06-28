#include<stdio.h>
#include<string>
using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string tempString;
        int max = 0;
        int index = 0;
        for(int i=0;i<s.size();i++) {
            index = tempString.find(s[i]);
            if(index == -1) {
                tempString.push_back(s[i]);
            } else {
                if(max < tempString.size())
                    max = tempString.size();
                tempString.erase(0, index + 1);
                tempString.push_back(s[i]);
            }
        }   
        if(max < tempString.size())
            max = tempString.size();
        return max;
    }
};

int main() {
    return 0;
}