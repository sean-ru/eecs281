#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int join_ropes(vector<int>& rope_lengths) {
        priority_queue<int, vector<int>, std::greater<int> > pq;
        int cost = 0;
        while (pq.size() > 1) {
            int rope1 = pq.top();
            pq.pop();
            int rope2 = pq.top();
            pq.pop();
            pq.push(rope1 + rope2);
            cost += (rope1 + rope2);
        }
        return cost;
    }
};