#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct DijkstraData {
    double d;
    int p;
    bool k;
    DijkstraData()
      : d { INT_MAX }, p{-1}, k{false} {}
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int> >& edges, vector<double>& succProb, int start, int end) {
        vector<DijkstraData> dijkstraTable(edges.size());
        dijkstraTable[start].d = 0;
        for (size_t count = 0; count < edges.size(); ++count) {
            int minDist = INT_MAX;
            size_t idx = 0;
            for (size_t i = 0; i < dijkstraTable.size(); ++i) {
                if (!dijkstraTable[i].k && dijkstraTable[i].d < minDist) {
                    minDist = dijkstraTable[i].d;
                    idx = i;
                }
            }
            if (minDist == INT_MAX) {
                return -1;
            }
            dijkstraTable[idx].k = true;
            for (size_t v = 0; v < edges.size(); ++v) {
                if (!dijkstraTable[v].k && edges[idx][v] && dijkstraTable[idx].d + edges[idx][v] < dijkstraTable[v].d) {
                    dijkstraTable[v].d = dijkstraTable[idx].d + edges[idx][v];
                }
            }
        }
        return dijkstraTable[end].d;
    }   
};




// class Solution {
// public:
//     int V, src, cost[100][100];
//     int dist[100];
//     bool visited[100] = {0};
//     int parent[100];

//     void init() {
//         for (int i = 0; i < V; ++i) {
//             parent[i] = i;
//             dist[i] = INT_MAX;
//         }
//         dist[src] = 0;
//     }

//     int getNearest() {
//         int minValue = INT_MAX;
//         int minNode = 0;
//         for (int i = 0; i < V; ++i) {
//             if (!visited[i] && dist[i] < minValue) {
//                 minValue = dist[i];
//                 minNode = i;
//             }
//         }
//         return minNode;
//     }

//     void dijkstra() {
//         for (int i = 0; i < V; ++i) {
//             int nearest = getNearest();
//             visited[nearest] = true;

//             for (int adj = 0; adj < V; ++adj) {
//                 if (cost[nearest][adj] != INT_MAX && dist[adj] > dist[nearest] + cost[nearest][adj]) {
//                     dist[adj] = dist[nearest] + cost[nearest][adj];
//                     parent[adj] = nearest;
//                 }
//             }
//         }
//     }
    
//     double maxProbability(int n, vector<vector<int> >& edges, vector<double>& succProb, int start, int end) {
        
//     }    

// };







// struct DijkstraData {
//     double d;
//     int p;
//     bool k;
//     DijkstraData()
//       : d { numeric_limits<double>::infinity() }, p{-1}, k{false} {}
// };

// using AdjList = vector<vector<pair<int, int> > >;
// using DistPair = pair<int, int>;

// class Solution {
// public:
//     double maxProbability(int n, vector<vector<int> >& edges, vector<double>& succProb, int start, int end) {
//         vector<DijkstraData> dijkstraTable(edges.size());
//         priority_queue<DistPair, vector<DistPair>, greater<DistPair> > pq;
//         dijkstraTable[start].d = 0;
//         pq.emplace(dijkstraTable[start].d, start);

//         while (!pq.empty()) {
//             auto [minDist, idx] = pq.top();
//             pq.pop();

//             if (minDist == numeric_limits<int>::max()) {
//                 return -1;
//             }

//             if (!dijkstraTable[idx].k) {
//                 dijkstraTable[idx].k = true;
//                 for (auto& neighborDistPair : edges[idx]) {
//                     auto [neighbor, dist] = neighborDistPair;
//                     int newDist = dijkstraTable[idx].d + dist;
//                     if (newDist < dijkstraTable[neighbor].d) {
//                         dijkstraTable[neighbor].d = newDist;
//                         dijkstraTable[neighbor].p = idx;
//                         pq.emplace(newDist, neighbor);
//                     }
//                 }
//             }
//         }
//         return dijkstraTable[end].d;
//     }
// };