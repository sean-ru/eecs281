#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    float dist (int x, int y, int a, int b) {
        return sqrt(pow((x - a), 2) + pow((y - b), 2));
    }
    
    int dfs(vector<int> adj[], vector<vector<int> >& bombs, int i, vector<bool>& visited ) {
        if (visited[i]) {
            return 0;
        }
        visited[i] = true;
        
        int x = 1;
        for (auto it : adj[i]) {
            if (!visited[it]) {
                x += dfs(adj, bombs, it, visited);
            }
        }
        return x;
    }
    
    int maximumDetonation(vector<vector<int> >& bombs) {
        vector<int> adj[bombs.size() + 1];
        for (int i = 0; i < bombs.size(); ++i) {
            for (int j = 0; j < bombs.size(); ++j) {
                if (i != j) {
                    if (dist(bombs[i][0], bombs[i][1], bombs[j][0], bombs[j][1]) <= bombs[i][2]) {
                        adj[i].push_back(j);
                    }
                    else if (dist(bombs[i][0], bombs[i][1], bombs[j][0], bombs[j][1]) <= bombs[j][2]) {
                        adj[j].push_back(i);
                    }
                }   
            }
        }
        
        int ans = 0;
        
        for (int i = 0; i < bombs.size(); ++i) {
            vector<bool> vis(bombs.size(), false);
            if (!vis[i]) {
                int x = dfs(adj, bombs, i, vis);
                ans = max(ans, x);
            }
        }
        return ans;
    }
};