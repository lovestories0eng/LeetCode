#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> result;
        int count = 0;
        int sizeAll = groupSizes.size();
        int arr[sizeAll];
        for(int i=0;i<sizeAll;i++) {
            arr[i] = i;
        }
        while (groupSizes.size() != 0) {
            vector<int> group;
            int size = groupSizes[0];
            int curSize = 0;
            for (int i=0;i<groupSizes.size();i++) {
                if (groupSizes[i] == size) {
                    group.insert(end(group), arr[i]);

                    groupSizes.erase(groupSizes.begin() + i);
                    for (int j=i;j<sizeAll - count - 1;j++) {
                        arr[j] = arr[j+1];
                    }
                    i--; curSize++; count++;
                } else {
                    continue;
                }
                if (curSize == size) {
                    result.insert(end(result), group);
                    break;
                }
            }
        }
        return result;
    }
};