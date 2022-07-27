#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int helper(vector<int>& nums, int i, vector<int>& memo) {
        if (i < 0) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        else {
            return memo[i] = max(helper(nums, i - 2, memo) + nums[i], helper(nums, i - 1, memo));
        }
    }
    
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return helper(nums, nums.size() - 1, memo);        
    }
};