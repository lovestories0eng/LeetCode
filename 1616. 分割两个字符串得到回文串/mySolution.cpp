#include "../stdc++.h"
using namespace std;

class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        int n = a.size();

        int aPrefixIndex, bPrefixIndex;

        for (int i = 0; i < n / 2; i++) {
            if (a[i] == b[n - 1 - i]) continue;
            else {
                aPrefixIndex = i;
                break;
            }
        }
        // 找到a的最大前缀
        if (aPrefixIndex >= n / 2) return true;

        for (int i = 0; i < n / 2; i++) {
            if (b[i] == a[n - 1 - i]) continue;
            else {
                bPrefixIndex = i;
                break;
            }
        }
        // 找到b的最大前缀
        if (bPrefixIndex >= n / 2) return true;

        int aIndex, bIndex;
        for (bIndex = aPrefixIndex; bIndex < n / 2; bIndex++) {
            if (b[bIndex] == b[n - 1 - bIndex]) continue;
            else break;
        }
        if (bIndex >= n / 2) return true;

        for (aIndex = aPrefixIndex; aIndex < n / 2; aIndex++) {
            if (a[aIndex] == a[n - 1 - aIndex]) continue;
            else break;
        }
        if (aIndex >= n / 2) return true;

        for (aIndex = bPrefixIndex; aIndex < n / 2; aIndex++) {
            if (a[aIndex] == a[n - 1 - aIndex]) continue;
            else break;
        }
        if (aIndex >= n / 2) return true;

        for (bIndex = bPrefixIndex; bIndex < n / 2; bIndex++) {
            if (b[bIndex] == b[n - 1 - bIndex]) continue;
            else break;
        }
        if (bIndex >= n / 2) return true;

        return false;
    }
};