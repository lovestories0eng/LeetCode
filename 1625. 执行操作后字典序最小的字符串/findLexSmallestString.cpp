#include "../stdc++.h"
using namespace std;

// 经典超时
class Solution {
public:
    bool exist(set<string>& trace, string& s) {
        if (trace.count(s) > 0) return true; 
        return false;
    }

    void dfs(string& s, set<string>& trace, string& ans, int a, int b) {
        if (s.compare(ans) < 0) ans = s;
        // 记录tmp，用于回溯
        string tmp = s;
        // 累加
        for (int i = 0; i < s.size(); i += 2) {
            s[i + 1] = (s[i + 1] - '0' + a) % 10 + '0';
        }
            
        // 没搜索到的直接记录
        if (!exist(trace, s)) {
            trace.insert(s);
            dfs(s, trace, ans, a, b);
        } 
        // tmp变量省去了回溯的步骤

        // 轮转
        for (int i = 0; i < s.size(); i++) {
            s[i] = tmp[i - b >= 0 ? i - b : s.size() - b + i];
        }
        if (!exist(trace, s)) {
            trace.insert(s);
            dfs(s, trace, ans, a, b);
        } 
    }

    string findLexSmallestString(string s, int a, int b) {
        string ans = s;
        // 保存当前已经追踪到的组合
        set<string> trace;
        dfs(s, trace, ans, a, b);
        return ans;
    }
};