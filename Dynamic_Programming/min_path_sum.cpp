#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int helper(int r, int c, vector<vector<int> >& grid, vector<vector<int> >& memo) {
        if (r == 0 && c == 0) {
            return grid[0][0];
        }
        if (r < 0 || c < 0) {
            return INT_MAX;
        }
        if (memo[r][c] != -1) {
            return memo[r][c];
        }
        else {
            return memo[r][c] = min(helper(r - 1, c, grid, memo), helper(r, c - 1, grid, memo)) + grid[r][c];
        }
    }
    
    int minPathSum(vector<vector<int> >& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<int> > memo(r, vector<int>(c, -1));
        return helper(r - 1, c - 1, grid, memo);
    }
};