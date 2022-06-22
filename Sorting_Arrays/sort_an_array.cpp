#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue <int, vector<int>, greater<int> > minHeap;  
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            minHeap.push(nums[i]);
        }
        
        for (int i = 0; i < n; ++i) {
            nums[i] = minHeap.top();
            minHeap.pop();
        }
        return nums;
    }
};