#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Data {
    int node, dist, val;
    Data(int node, int dist, int val) {
        this->node = node;
        this->dist = dist;
        this->val = val;
    }
};

struct Comparator {
    bool operator() (Data a, Data b) {
        return !(a.val < b.val);
    }
};

class Solution {
public:
    vector<vector<int> > cost;
    int findCheapestPrice(int n, vector<vector<int> >& flights, int src, int dst, int k) {
        cost = vector<vector<int> >(n + 1, vector<int>(k + 10, INT_MAX));
        vector<vector<int> > graph[n];
        for (int i = 0; i < flights.size(); ++i) {
            int u = flights[i][0];
            int v = flights[i][1];
            graph[u].push_back( {v, flights[i][2]} );
        }
        priority_queue<Data, vector<Data>, Comparator> pq;
        pq.push(Data(src, 0, 0));
        cost[src][0] = 0;
        int ans = -1;
        while (!pq.empty()) {
            Data temp = pq.top();
            int curr = temp.node;
            pq.pop();
            int dist = temp.dist;
            if (curr == dst) {
                return temp.val;
            }
            ++dist;
            if (dist > k + 1) {
                continue;
            }
            for (int i = 0; i < graph[curr].size(); ++i) {
                int neighbor = graph[curr][i][0];
                if (cost[neighbor][dist] > cost[curr][dist - 1] + graph[curr][i][1]) {
                    cost[neighbor][dist] = cost[curr][dist - 1] + graph[curr][i][1];
                    pq.push(Data(neighbor, dist, cost[neighbor][dist]));
                }
            }
        }
        return -1;
    }
};