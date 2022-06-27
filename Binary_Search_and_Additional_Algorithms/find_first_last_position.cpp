#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int binarySearch(int left, int right, vector<int>& nums, int target) {
        int middle; 
        while (left <= right) {
            middle = left + (right - left)/2;
            if (target == nums[middle]) {
                return middle;
            }
            else if (target > nums[middle]) {
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> notFound;
        notFound.push_back(-1);
        notFound.push_back(-1);
        vector<int> found;

        int middle = binarySearch(0, n - 1, nums, target);
        if (middle == -1) {
            return notFound;
        }
        int right = middle;
        while (right < n) {
            int t = binarySearch(right + 1, n - 1, nums, target);
            if (t == -1 || right == t) {
                break;
            }
            right = t;
        }
        
        int left = middle;
        
        while (left >= 0) {
            int t = binarySearch(0, left - 1, nums, target);
            if (t == -1 || left == t) {
                break;
            }
            left = t;
        }
        
        found.push_back(left);
        found.push_back(right);
        return found;
    }
};