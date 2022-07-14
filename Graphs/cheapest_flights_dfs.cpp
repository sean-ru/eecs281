#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int k, dst, numStops, stop;
    
    int helper(int stop, int numStops) {
        if (numStops > k) {
            return INT_MAX;
        }
        else if (stop == dst) {
            return 0;
        }
    }
    
    
    
    int findCheapestPrice(int n, vector<vector<int> >& flights, int src, int dst, int k) {
        
        
        if (src == dst) {
            return 
        }
        
        
        
        
        int cheapestFlight = INT_MAX;
        for (auto flight : flights) {
            if (flight[0] = stop) {
                cheapestFlight = min(cheapestFlight, flight[2] + helper(flight[1], numStops + 1));
            }
        }
        cheapestFlight = helper(src, -1);
        if (cheapestFlight != INT_MAX) {
            return cheapestFlight;
        }
        return -1;
    }
};