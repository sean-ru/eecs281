#include <iostream>
#include <vector>
using namespace std;

class Solution {
typedef pair<int, int> pi;
    public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      
        vector<int > cost (n+1, 100000007) ;

        cost[k] =  0 ;
        vector<pair<int , int >> adj[n+1] ;
         int u, v , w ;
        for(int i =0 ; i < times.size() ; i++)
        {
             u = times[i][0] ;
             v = times[i][1] ;
            w = times[i][2] ;
            adj[u].push_back(make_pair(v ,w)) ;
        }
         priority_queue<pi, vector<pi>, greater<pi> > pq;
        
        pq.push(make_pair(k, cost[k])) ;
        while(!pq.empty())
        {
             u = pq.top().first;
            pq.pop() ;
          for(auto it : adj[u])
            {
                 v = it.first ;
                 w = it.second ;
              if( cost[v] > w + cost[u] )
              {
                   cost[v] = w + cost[u] ;
                  pq.push(make_pair(v ,cost[v])) ;
              }
            }
        }
     int ans = -1 ;
        for(int i =1 ; i <=n ; i++ )
        {
            cout<<cost[i] <<" " ;
            if(cost[i] == 100000007){
                     return -1 ;   
            }
            if(ans < cost[i] ) ans = cost[i] ;
        }
        return ans ;
    }
};