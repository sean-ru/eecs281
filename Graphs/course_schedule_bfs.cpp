#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:    
    // vector<int> topologicalSort(vector<vector<int> > adjList) {
    //     vector<int> inDegrees(adjList.size(), 0);
    //     for (auto& row : adjList) {
    //         for (int vertex : row) {
    //             ++inDegrees[vertex];
    //         }
    //     }
    
    //     vector<int> result;
    //     queue<int> bfs;
    //     for (size_t vertex = 0; vertex < adjList.size(); ++vertex) {
    //         if (inDegrees[vertex] == 0) {
    //             bfs.push(vertex);
    //         }
    //     }
    //     while (!bfs.empty()) {
    //         int curr = bfs.front();
    //         bfs.pop();
    //         result.push_back(curr);
    //         for (int neighbor : adjList[curr]) {
    //             if (--inDegrees[neighbor] == 0) {
    //                 bfs.push(neighbor);
    //             }
    //         }
    //     }
    //     return result;
    // }


    // vector<int> findTopologicalOrdering(vector<vector<int> > adjList) {
    //     int n = adjList.size();
    //     vector<int> inDegree(n, 0);
    //     for (int i = 0; i < n; ++i) {
    //         for (int j = 0; j < adjList[0].size(); ++j) {
    //             inDegree[j]++;
    //         }
    //     }
    //     queue<int> q;
    //     for (int i = 0; i < n; ++i) {
    //         if (inDegree[i] == 0) {
    //             q.push(i);
    //         }
    //     }
    //     int index = 0;
    //     vector<int> order(n, 0);
    //     while (!q.empty()) {
    //         int at = q.front();
    //         order[index++] = at;
    //         for (int i = 0; i < adjList[at].size(); ++i) {
    //             inDegree[i] = inDegree[i] - 1;
    //             if (inDegree[i] == 0) {
    //                 q.front();
    //             }
    //         }
    //     }
    //     if (index != n) {
    //         return {};
    //     }
    //     return order;
    // }



    vector<int> scheduleCourses(int n, vector<vector<int> >& prereqs) {
        vector<vector<int> > adjList(n);
        vector<int> inDegrees(adjList.size(), 0);
        for (auto& prereq : prereqs) {
            adjList[prereq[1]].push_back(prereq[0]);
            ++inDegrees[prereq[0]];
        }
        vector<int> result;
        queue<int> bfs;
        for (int course = 0; course < n; ++course) {
            if (inDegrees[course] == 0) {
                bfs.push(course);
            }
        }
        while (!bfs.empty()) {
            int curr = bfs.front();
            bfs.pop();
            result.push_back(curr);
            for (int neighbor : adjList[curr]) {
                if (--inDegrees[neighbor] == 0) {
                    bfs.push(neighbor);
                }
            }
        }
        return result;
    }

    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
        // queue<int> q;
        // vector<int> inDegree(numCourses, 0);
        // for (int i = 0; i < numCourses; ++i) {
        //     for (int j = 0; j < prerequisites[0].size(); ++j) {
        //         ++inDegree[prerequisites[0][j]];
        //     }
        // }
        // for (int i = 0; i < numCourses; ++i) {
        //     if (inDegree[i] == 0) {
        //         q.push(i);
        //     }
        // }
        // int count = 0;
        // while (!q.empty()) {
        //     int node = q.front();
        //     q.pop();
        //     count++;
        //     for (int i = 0; i < prerequisites[0].size(); ++i) {
        //         inDegree[prerequisites[0][i]]--;
        //         if (inDegree[prerequisites[0][i]] == 0) {
        //             q.push(prerequisites[0][i]);
        //         }
        //     }
        // }
        // if (count == numCourses) {
        //     return false;
        // }
        // return true;

        if (!scheduleCourses(numCourses, prerequisites).empty()) {
            return true;
        }
        return false;
    }
};    