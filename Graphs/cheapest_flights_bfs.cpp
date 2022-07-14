#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int> >& flights, int src, int dst, int k) {
        vector<vector<pair<int, int> > > graph(n);
        for (int i = 0; i < flights.size(); ++i) {
            graph[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));
        }
        int minCost = INT_MAX;
        ++k;

        queue<pair<int, int> > q;

        int level = 0;

        q.push(make_pair(src, 0));
        while (!q.empty() && level <= k) {
            ++level;

            int count = q.size();
            while (count--) {
                int node = q.front().first;
                int cost = q.front().second;
                q.pop();
                if (cost > minCost) {
                    continue;
                }

                if (node == dst) {
                    minCost = min(minCost, cost);
                    continue;
                }

                for (int i = 0; i < graph[node].size(); ++i) {
                    q.push(make_pair(graph[node][i].first, graph[node][i].second + cost));
                }
            }
        }
        if (minCost == INT_MAX) {
            return -1;
        }
        return minCost;
    }
};