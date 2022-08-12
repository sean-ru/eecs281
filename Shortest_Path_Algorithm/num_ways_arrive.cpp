#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	#define f first    
	#define s second
	using ll = long long;   
	using p = pair<ll,ll>;
	const int mod = 1e9+7;

	int countPaths(int n, vector<vector<int>>& roads) {
		vector<p> g[n];
		for(auto& r : roads){
			g[r[0]].push_back({r[1],r[2]});            
			g[r[1]].push_back({r[0],r[2]});
		}

		vector<ll> dis(n, LONG_MAX), way(n,0);
		dis[0] = 0;
        way[0] = 1;

		priority_queue<p, vector<p>, greater<p> > q;
		q.push({dis[0],0});

		while(!q.empty()){
			auto cur = q.top(); q.pop();
			int u = cur.s;
			if(cur.f > dis[u])continue;
			for(auto& nei : g[u]){
				int v = nei.f;
				int w = nei.s;
				if(dis[u]+w < dis[v]) {
					way[v] = way[u];
					dis[v] = dis[u]+w;
					q.push({dis[v],v});
				}else if(dis[u]+w == dis[v]) {
					way[v]  = (way[v] + way[u]) % mod;
				}
			}
		}
		return way[n-1] % mod;
	}
};





// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// class Solution {
// public:
//     int countPaths(int n, vector<vector<int> >& edges) { 
//         vector<vector<long long> > adj[n];
//         for (int i = 0; i < edges.size(); ++i) {
//             int u = edges[i][0];
//             int v = edges[i][1];
//             int w = edges[i][2];
//             vector<long long> vec1;
//             vec1.push_back(v);
//             vec1.push_back(w);
//             vector<long long> vec2;
//             vec2.push_back(u);
//             vec2.push_back(w);

//             adj[u].push_back(vec1);
//             adj[v].push_back(vec2);
//         }
         
//         vector<long long> dist(n, LLONG_MAX);
//         vector<long long> dp(n, 0);
        
//         priority_queue<vector<long long>, vector<vector<long long> >, greater<vector<long long> > > pq;
        
//         dist[0] = 0;
//         dp[0] = 1;
        
//         vector<long long> vec3;
//         vec3.push_back(0);
//         vec3.push_back(0);
//         pq.push(vec3);
//         while(!pq.empty()) {
//             auto t = pq.top();
//             pq.pop();
            
//             long long node = t[1];
//             long long time = t[0];
            
//             for(int i=0;i<adj[node].size();i++) {
//                 long long x = adj[node][i][0];
//                 long long w = adj[node][i][1];
//                 if (dist[x] == (long long) w + time) {
//                     dp[x]=(dp[x] + dp[node]) % (long long) 1e9 + 7;
//                 }
//                 if (dist[x] > w + time) {
//                     dist[x] = (long long) w + time;
//                     vector<long long> vec4;
//                     vec4.push_back((long long) w + time);
//                     vec4.push_back(x);
//                     pq.push(vec4);
//                     dp[x] = dp[node];
//                 }
//             }
//         }
//         return dp[n-1] % (long long) 1e9 + 7;   
//     }
// };    