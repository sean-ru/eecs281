#include <iostream>
#include <vector>
class Solution {
public:
    void duplicateZeros(std::vector<int>& arr) {
        int orig_size = arr.size();
        for (int i = 0; i < orig_size; ++i) {
            if (arr[i] == 0) {
                arr.insert(arr.begin() + i, 0);
                i++;
            }
        }
        arr.resize(orig_size);
    }
};