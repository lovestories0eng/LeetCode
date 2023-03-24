#include "../stdc++.h"
using namespace std;


class Solution {
public:
    // 假设当前需要填入第 i 位，且前面填入的数字与 n 对应位置的数字不相同，
    // 那么需要求得的不重复数字的正整数个数只与 mask 相关，我们可以使用备忘录 dp 记录该结果，避免重复计算。
    vector< vector<int> > dp;

    /*
        @param mask: 掩码，记录前面已经填入过的数字
        @param sn: 原字符串
        @param i: 当前填入第 i 位数
        @param same: 前面填入的数字与 n 的对应位置的数是否相同
        return： 在整数区间 [0,n] 之间的没有重复数字的正整数个数
    */
    int f(int mask, const string &sn, int i, bool same) {
        // 在掩码确定、位数确定的情况下，只能返回 1
        if (i == sn.size()) {
            return 1;
        }
        // 当前填入第 i 位，且前面填入的数字与 n 对应位置的数字不相同，那么需要求得的不重复数字的正整数个数只与 mask 相关
        // 如果前面填入的数字与 n 对应位置数字相同，那么不能取遍所有值
        // 需要 !same 的原因：mask只能知道前面有了哪些数，不能知道前面那些数的顺序
        // 假设 n = 415
        // 当前缀为"14X"或者"41X"时，一个值为8，一个值为4
        // "14X"是肯定先算出来的，因此到了"41X"的时候，直接返回而不计算后面的值了
        // 由于最终答案是减掉不重复的数，因此这里多加了四，最终答案就会减4
        if (!same && dp[i][mask] >= 0) {
            // 返回当前情况下不重复数字的个数
            return dp[i][mask];
        }
        // t: 当前位可遍历到的最大值
        // 如果前面填入的数字与 n 对应位置的数字相同，那么可选的填入数字小于等于 n 在第 i 位的数字，否则可填入全部数字
        int res = 0, t = same ? (sn[i] - '0') : 9;
        for (int k = 0; k <= t; k++) {
            // 判断是否填过了 k ，填过了则跳过，前缀都是0的情况可以避免
            if (mask & (1 << k)) {
                continue;
            }
            res += f(
                // 令掩码对应位数置为 1
                // 前缀都是 0时，0 | (1 << 0) = 1，需要特殊处理
                mask == 0 && k == 0 ? mask : mask | (1 << k), 
                sn, 
                // 位数加一
                i + 1,
                // 做 && 运算，代表前面填入的数字是否每一位都与 n 对应位数字相同
                same && k == t
            );
        }
        
        // 只要对应位数有一位与 n 不同
        if (!same) {
            // 记录当前 mask 情况时，可能的不重复数字
            dp[i][mask] = res;
        }

        return res;
    }

    int numDupDigitsAtMostN(int n) {
        string sn = to_string(n);
        // 整数掩码 mask 记录前面已经填入过的数字（注意前缀 0 不计入已填入的数字）
        // 位数， 是否填了 1～10， 10000000000
        dp.resize(sn.size(), vector<int>(1 << 10, -1));
        // f初始状态
        // mask: 0 -> 代表 0 ～ 9 之中一个数都没选
        // sn
        // i: 0 -> 代表从最高位开始
        // same : 默认为true，因为最高位不一定0~9都能遍历到 -> n = 201，i = 0时，填入0、1时为false，填入2时为true
        return n + 1 - f(0, sn, 0, true);
    }
};

int main() {
    Solution s;
    cout << s.numDupDigitsAtMostN(415) << endl;;
}