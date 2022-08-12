#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int sizeAll = groupSizes.size();
        // ���groupSizes�е�ĳһλ���Ƿ�ʹ�ù�
        int arr[sizeAll];
        for (int i=0;i<sizeAll;i++) 
            arr[i] = 0;
        vector<vector<int>> result;
        int count = 0;
        while (count != groupSizes.size()) {
            vector<int> group;
            int size;
            for (int i=0;i<groupSizes.size();i++) {
                if (arr[i] == 0)
                    size = groupSizes[i];
            }
            int curSize = 0;
            for (int i=0;i<groupSizes.size();i++) {
                if (groupSizes[i] == size && arr[i] != 1) {
                    group.insert(end(group), i);
                    arr[i] = 1;
                    curSize++;
                    count++;
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