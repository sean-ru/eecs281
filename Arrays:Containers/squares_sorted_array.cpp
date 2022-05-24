#include <iostream>
#include <cstdlib>
#include <vector>

class Solution {
public: 
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] *= nums[i];
        }
        std::sort(begin(nums), end(nums));
        return nums;
    }
};