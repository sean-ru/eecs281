#include <iostream>
#include <vector>
class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        for (int i = m; i < m + n; ++i) {
            nums1[i] = nums2[i - m];
        }
        sort(begin(nums1), end(nums1));
    }
};