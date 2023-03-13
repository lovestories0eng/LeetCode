#include "../stdc++.h"
using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int sum = 0;
        int tsum = 1;
        if (k <= 1)
            return 0;
        // 滑动窗口
        for (int i = 0, j = 0; i < nums.size(); i++)
        {
            tsum *= nums[i];
            while (tsum >= k)
            {
                tsum /= nums[j];
                j++;
            }
            sum += i - j + 1;
        }
        return sum;
    }
};