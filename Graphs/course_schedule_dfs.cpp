#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:    
    bool isCycle(int node, vector<vector<int> >& adj, vector<int>& visited, vector<int>& order) {
        visited[node] = 1;
        order[node] = 1;
        bool ans = false;
        for (auto it : adj[node]) {
            if (visited[it] && order[it]) {
                return true;
            }    
            else if (visited[it] == 0) {
                ans = ans || isCycle(it, adj, visited, order);
            }    
        }
        order[node] = 0;
        return ans;
    }

    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int> >adj(numCourses);
        for (int i = 0; i < n; ++i) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }    
        vector<int>visited(numCourses, 0);
        vector<int>order(numCourses, 0);
        for (int i = 0; i < numCourses; ++i)
        {
            if (visited[i] == 0) {
                if(isCycle(i, adj, visited, order)) { 
                    return false;
                }    
            }
        }
        return true;
    }
};    