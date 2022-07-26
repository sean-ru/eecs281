#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    static bool comp(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]]++;
        }    
        vector<pair<int,int> > vec(m.begin(), m.end());
        sort(vec.begin(), vec.end(), comp);
        for (int i = 0; i < k; ++i) {
            ans.push_back(vec[i].first);
        }    
        return ans;
    }   
};