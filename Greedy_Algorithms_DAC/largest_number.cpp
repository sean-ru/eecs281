#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    static bool comp(string& s1, string& s2) {
        if ((s1+s2) > (s2+s1)) {
            return true;
        }     
        return false;
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string> vec;
        string ans;
        
        for (auto& num : nums) {
            vec.push_back(to_string(num));
        }    
        
        sort(vec.begin(), vec.end(), comp);
        
        for (auto& it : vec)
            ans += it;
        
        int i = 0;
        
        while (i < ans.length() && ans[i] == '0') {
            i++;
        }
        
        if (i == ans.length()) {
            return "0";
        }
        
        return ans;
    }
};