#include <iostream>
#include <vector>
class Solution {
public:
    int findNumbers(std::vector<int>& nums) {
        int even_count = 0;
        for (int i = 0; i < nums.size(); ++i) {  
            int digits_count = 0;
            while (nums[i] > 0) {
                nums[i] = nums[i]/10;
                digits_count++;
            }
            if (digits_count % 2 == 0) {
                even_count++;
            }
        }
        return even_count;
    }
};