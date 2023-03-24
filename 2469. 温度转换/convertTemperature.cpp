#include "../stdc++.h"
using namespace std;

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> ans;
        ans.emplace_back(celsius + 273.15);
        ans.emplace_back(celsius * 1.8 + 32);
        return ans;
    }
};