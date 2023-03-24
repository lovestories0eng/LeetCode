#include "../stdc++.h"
using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int size = roads.size();
        vector<vector<int>> graph(n, vector<int>(0));
        for (int i = 0; i < size; i++) {
            int startPoint = roads[i][0];
            int endPoint = roads[i][1];
            graph[startPoint].push_back(endPoint);
            graph[endPoint].push_back(startPoint);
        }

        int maxRank = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int curRank = graph[i].size() + graph[j].size();
                if (find(graph[i].begin(), graph[i].end(), j) != graph[i].end()) curRank--;
                if (curRank > maxRank) maxRank = curRank;
            }
        }
        return maxRank;
    }
};