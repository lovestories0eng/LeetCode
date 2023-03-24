#include "../stdc++.h"
using namespace std;

class Solution {
public:
    void dfs(
        string& s, 
        vector<string>& dictionary, 
        string& candidate, 
        string curStr, 
        int idx, 
        int& global)
    {
        if (idx > s.size()) return;
        bool flag = false;
        if (curStr.size() > 0)
            for (int i = 0; i < dictionary.size() && (int)dictionary[i].size() >= global; i++) {
                if (curStr.size() == dictionary[i].size() && curStr == dictionary[i]) {
                    if ((int)curStr.size() > global) {
                        candidate = dictionary[i];
                        global = curStr.size();
                        flag = true;
                        break;
                    } else if ((int)curStr.size() == global && curStr.compare(candidate) < 0) {
                        candidate = dictionary[i];
                        flag = true;
                        break;
                    }
                // 当前字符串的长度小于字典中某个元素的长度
                } else if (curStr.size() < dictionary[i].size()) {
                    // 当前字符串与字典中某个元素的前几位匹配
                    if (
                        dictionary[i].substr(0, curStr.size()).compare(curStr) == 0
                        // 当前字符串可能的最大长度
                        && curStr.size() + s.size() - idx >= dictionary[i].size()
                    ) {
                        flag = true; break;
                    }
                }
            }

        // 如果当前字符串与字典中任意元素都不匹配并且不是其从0开始的子串
        if (!flag && curStr.size() > 0) return;
        // 选择当前字母
        curStr += s[idx];
        dfs(s, dictionary, candidate, curStr, idx + 1, global);
        // 回溯，去掉最后一个字母
        curStr = curStr.substr(0, curStr.size() - 1);
        
        // 跳过当前字母
        dfs(s, dictionary, candidate, curStr, idx + 1, global);
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        int n = dictionary.size(), global = -1;
        string candidate;
        string curStr = "";
        dfs(s, dictionary, candidate, curStr, 0, global);

        return candidate;
    }
};

int main() {
    Solution s;
    string str = "aaa";
    vector<string> tmp;
    tmp.push_back("aaa");
    tmp.push_back("aa");
    tmp.push_back("a");
    s.findLongestWord(str, tmp);
}