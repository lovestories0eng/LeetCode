#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        map<int, int> mp;
        for (int i=0;i<position.size();i++) {
            if (mp.count(position[i])) {
                mp[position[i]]++;
            } else {
                mp[position[i]] = 1;
            }
        }
        int odd = 0, even = 0;
        for(auto it : mp) {
            if (it.first % 2 == 1) {
                odd += it.second;
            } else {
                even += it.second;
            }
        }
        if (odd > even)
            return even;
        else 
            return odd;
    }
};

int main() {

    return 0;
}