#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int> >& edges, int distanceThreshold) {
        int dist[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = INT_MAX;
                if (i == j) {
                    dist[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < edges.size(); ++i) {
            dist[edges[i][0]][edges[i][1]] = edges[i][2];
            dist[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                if (i != k) {
                    for (int j = 0; j < n; ++j) {
                        if (j != k && dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                        }
                    }
                }
            }
        }
        int count = INT_MAX;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int c = 0;
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] <= distanceThreshold) {
                    ++c;
                }
            }
            if (count >= c) {
                count = c;
                ans = i;
            }
        }
        return ans;
    }
};