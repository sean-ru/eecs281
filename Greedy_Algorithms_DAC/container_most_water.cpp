#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int width = 0;
        while (left < right) {
            int length = right - left;
            if (height[left] <= height[right]) {
                width = max(width, length * height[left]);
                left++;
            }
            else {
                width = max(width, length * height[right]);
                right--;
            }
        }
        return width;
    }
};