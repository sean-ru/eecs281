#include <iostream>
#include <vector>
using namespace std;

struct FWData {
    double d;
    int p;
    FWData()
      : d{std::numeric_limits<double>::infinity() }, p{-1} {}
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int> >& edges, vector<double>& succProb, int start, int end) {
        
    }
};