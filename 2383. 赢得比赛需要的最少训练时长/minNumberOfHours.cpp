#include "../stdc++.h"
using namespace std;

class Solution {
public:
    // initialEnergy: 初始精力
    // initialExperience: 初始经验
    // energy: 第 i 个对手的精力 -
    // experience: 第 i 个对手的经验 +
    int minNumberOfHours(
        int initialEnergy, 
        int initialExperience, 
        vector<int>& energy, 
        vector<int>& experience
        ) {
        int sumEnergy = 0, sumExperience = 0, hours = 0, size = energy.size();
        for (int i = 0; i < size; i++) {
            sumEnergy += energy[i];
            sumExperience += experience[i];
        }
        hours += initialEnergy > sumEnergy 
                    ? 0 
                    // 需要严格大于，所以需要加一
                    : sumEnergy - initialEnergy + 1;
        for (int i = 0; i < size; i++) {
            if (initialExperience > experience[i]) {
                initialExperience += experience[i];
            } 
            else {
                // 需要严格大于，所以需要加一
                hours += experience[i] - initialExperience + 1;
                initialExperience += (2 * experience[i] - initialExperience) + 1;
            }
        }
        return hours;
    }
};