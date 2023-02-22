#include<vector>
#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> result;
        map<int, int> hash_map;
        int size1 = items1.size(); int size2 = items2.size();
        for (int i=0;i<size1;i++) {
            if (hash_map.find(items1[i][0]) == hash_map.end()) {
                hash_map[items1[i][0]] = items1[i][1];
            } else {
                hash_map[items1[i][0]] += items1[i][1];
            }
        }
        for (int i=0;i<size2;i++) {
            if (hash_map.find(items2[i][0]) == hash_map.end()) {
                hash_map[items2[i][0]] = items2[i][1];
            } else {
                hash_map[items2[i][0]] += items2[i][1];
            }
        }
        for(auto it : hash_map) {
            vector<int> tmp;
            tmp.insert(tmp.end(), it.first);
            tmp.insert(tmp.end(), it.second);
            result.insert(result.end(), tmp);
        }
        return result;
    }
};