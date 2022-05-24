#include <vector>
#include <iostream>
class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int count = 0;
        int max_count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                count++;
                max_count = std::max(max_count, count);
            }
            else {
                count = 0;
            }
        }
        return max_count;
    }
};