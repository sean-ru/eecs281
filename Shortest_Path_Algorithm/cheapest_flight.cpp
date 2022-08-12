#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int> >& flights, int src, int dst, int k) {
        vector<int> dis(n,1e7);
        dis[src] = 0;
        for(int stops = 0; stops <= k; stops++) {
            vector<int> ndis = dis;
            for(int i = 0; i < flights.size(); i++) {
                ndis[flights[i][1]] = min(dis[flights[i][0]] + flights[i][2],ndis[flights[i][1]]);
            }
            dis = ndis;
        }
        if (dis[dst] >= 1e7) {
            return -1;
        }
        return dis[dst];
    }     
};