#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() - 1;
        int jump = 0;
        int i = 0;
        
        while (i < n && jump < n) {
            jump = max(jump, nums[i] + i);
            if (i >= jump) {
                return false;
            }
            ++i;
        }
        return true;
    }
};