#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > group;
        map<string, vector<string> > m;
        
        for (auto s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            m[key].push_back(s);
        }
        
        for (auto vec : m) {
            group.push_back(vec.second);
        }
        return group;
    }
};