#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string greatestNumber(vector<string>& vec) {
        string greatest = vec[0];
        for (int i = 1; i < vec.size(); ++i) {
            if (greatest.length() == vec[i].length()) {
                if (greatest.substr(0, 1) == vec[i].substr(0, 1)) {
                    if (vec[i].substr(1, 2).compare(greatest.substr(1,2)) > 0) {
                        greatest = vec[i];
                    }
                }
                if (vec[i].substr(0, 1).compare(greatest.substr(0, 1)) > 0) {
                    greatest = vec[i];
                }
            }
            else {
                if (vec[i].substr(0, 1).compare(greatest.substr(0, 1)) == 0) {
                    if (vec[i].substr(1, 2).compare(greatest.substr(0, 1)) > 0) {
                        greatest = vec[i];
                    }
                }
                if (vec[i].substr(0, 1).compare(greatest.substr(0, 1)) > 0) {
                    greatest = vec[i];
                }
            }
        }
        return greatest;
    }

    string makeString(vector<string>& vec) {
        string ans;
        int n = vec.size();
        for (int i = 0; i < n; ++i) {
            ans += greatestNumber(vec);
            vec.erase(find(vec.begin(), vec.end(), greatestNumber(vec)));
        }
        return ans;        
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string> numStrings;
        for (auto& num : nums) {
            numStrings.push_back(to_string(num));
        }
        return makeString(numStrings);
    }
};