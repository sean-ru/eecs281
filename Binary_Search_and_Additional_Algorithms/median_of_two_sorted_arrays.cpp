#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        for (auto num1 : nums1) {
            nums.push_back(num1);
        }
        for (auto num2 : nums2) {
            nums.push_back(num2);
        }
        sort(nums.begin(), nums.end());
        if (nums.size() % 2 == 0) {
            return (double) (nums[(nums.size() - 1)/2] + nums[nums.size()/2])/2;
        }
        else {
            return (double) nums[(nums.size() - 1)/2];
        }
    }
};