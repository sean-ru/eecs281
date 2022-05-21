//main.cpp
// Project UID db1f506d06d84ab787baf250c265e24e
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <map>
#include <cmath>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row_nums;
        row_nums.push_back(1);
        if (rowIndex == 0) {
            return row_nums;
        }
        if (rowIndex == 1) {
            row_nums.push_back(1);
            return row_nums;
        }
        vector<int> prev_row = getRow(rowIndex - 1);
        for (int col = 2; col < rowIndex + 1; ++col) {
            row_nums.push_back(prev_row[col - 2] + prev_row[col - 1]);
        }
        row_nums.push_back(1);
        return row_nums;
    }
};


int main()
{
    cout << "bulid" << endl;
    return 0;
}