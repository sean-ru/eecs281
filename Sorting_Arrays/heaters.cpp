#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int ans = INT_MIN;
        int left_dist = INT_MAX;
        int right_dist = INT_MAX;
        int n = heaters.size();
        for (int i = 0; i < houses.size(); ++i) { 
            int index = lower_bound(heaters.begin(), heaters.end(), houses[i]) - heaters.begin();
            if (index > 0) {
                left_dist = houses[i] - heaters[index - 1];
            }
            else {
                left_dist = INT_MAX;
            }
            if (index < n) {
                right_dist = heaters[index] - houses[i];
            }
            else {
                right_dist = INT_MAX;
            }
            ans = max(ans, min(right_dist, left_dist));
        }
        return ans;
    }
};