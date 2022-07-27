#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int helper(int m, int n, vector<vector<int> >& memo) {
        if (m == 1 && n == 1) {
            return 1;
        }
        if (m < 1 || n < 1) {
            return 0; 
        }
        if (memo[m][n] != 0) {
            return memo[m][n];
        }
        else {
            return memo[m][n] = helper(m - 1, n, memo) + helper(m, n - 1, memo);
        }
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int> > memo(m + 1, vector<int>(n + 1));
        return helper(m, n, memo);
    }
};