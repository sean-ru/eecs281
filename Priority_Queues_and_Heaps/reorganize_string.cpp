#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool sortByVal(const pair<char, int>& a, const pair<char, int>& b) {
    return a.second > b.second;
}

class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> charFreq;
        string output = "";
        for (int i = 0; i < s.length(); ++i) {
            if (charFreq.find(s[i]) == charFreq.end()) {
                charFreq.insert(make_pair(s[i], 1));
            }
            else {
                charFreq[s[i]]++;
            }
        }

        vector<pair<char, int> > vec;

        map<char, int>::iterator it2;
        for (it2 = charFreq.begin(); it2 != charFreq.end(); ++it2) {
            vec.push_back(make_pair(it2->first, it2->second));
        }

        sort(vec.begin(), vec.end(), sortByVal);
        
        for (auto& item : vec) {
            cout << item.first << " " << item.second << endl;
        }
        
        output += vec[0].first;
        vec[0].second--;
        cout << output << endl;
        for (int i = 1; i < s.length(); ++i) {
            for (auto& item : vec) {
                if (item.first != output[i-1] && item.second > 0) {
                    cout << " " << item.first << item.second << endl;
                    output += item.first;
                    item.second--;
                    break;
                }
            }
            sort(vec.begin(), vec.end(), sortByVal);
            
        }
        cout << output << endl;
        if (output.size() == s.size()) {
            return output;
        }
        else
            return "";
    }
};