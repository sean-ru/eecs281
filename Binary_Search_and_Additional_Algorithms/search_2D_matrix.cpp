#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& vec, int target, int left, int right) {
        while (right > left) {
            int mid = left + (right - left)/2;
            if (target == vec[mid]) {
                return mid;
            }
            else if (target < vec[mid]) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return -1;
    }
    
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        vector<int> vec;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                vec.push_back(matrix[i][j]);
            }
        }
        if (binarySearch(vec, target, 0, vec.size()) == -1) {
            return false;
        }
        return true;
    }
};