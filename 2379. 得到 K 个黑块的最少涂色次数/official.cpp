#include "../stdc++.h"
using namespace std;

/** 
 * 我们只需要在「滑动窗口」从左向右移动的过程中维护窗口中白色块的数目，
 * 最后返回移动过程中白色块数目的最小值即为我们需要至少出现一次连续
 * k个黑色块的最少操作次数。
**/
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // 创建滑动窗口
        // 滑动窗口的区间为[l, r - 1]
        int l = 0, r = 0, cnt = 0;
        while (r < k) {
            cnt += blocks[r] == 'W' ? 1 : 0;
            r++;
        }
        r--;

        int res = cnt;
        while (r < blocks.size() - 1) {
            l++; r++;
            // 右边新出现白色块则加一
            cnt += blocks[r] == 'W' ? 1 : 0;
            // 由于滑动窗口向右移动，所以需要去掉原来的白块
            cnt -= blocks[l - 1] == 'W' ? 1 : 0;
            res = min(res, cnt);
        }
        return res;
    }
};