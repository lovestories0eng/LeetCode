#include "../stdc++.h"
using namespace std;

// array.length = 100000时超时
class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int n = array.size();
        int count_letter[n + 1], count_num[n + 1];
        count_letter[0] = 0; 
        count_num[0] = 0;

        int sum_letter = 0, sum_num = 0;
        for (int i = 0; i < n; i++) {
            if (array[i][0] >= 'A' && array[i][0] <= 'Z' 
            || (array[i][0] >= 'a' && array[i][0] <= 'z')) {
                sum_letter += 1;
            } else if (array[i][0] >= '0' && array[i][0] <= '9') {
                sum_num += 1;
            }
            count_letter[i + 1] = sum_letter;
            count_num[i + 1] = sum_num;
        }

        int max_length = INT_MIN;
        int start, end;
        // i += 2，因为奇数个不可能存在数字数目与字母数目相等的情况
        for (int i = 0; i < n + 1; i++) {
            for (int j = i + 1; j < n + 1; j++) {
                if ((j - i) % 2 != 0) continue;
                int sub_letter = count_letter[j] - count_letter[i];
                int sub_num = count_num[j] - count_num[i];
                if (sub_letter == sub_num && j - i > max_length) {
                    max_length = j - i;
                    start = i;
                    end = j;
                }
            }
        }
        vector<string> vec;
        if (max_length == INT_MIN) return vec;
        vector<string> result(array.begin() + start, array.begin() + end);
        return result;
    }
};