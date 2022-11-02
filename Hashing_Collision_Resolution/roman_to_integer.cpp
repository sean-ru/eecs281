#include <unordered_map>
#include <string>
using namespace std;

class Solution {
private:
    unordered_map<char, int> um;
public:
    int romanToInt(string s) {
        unordered_map<char, int> um;
        um['I'] = 1;
        um['V'] = 5;
        um['X'] = 10;
        um['L'] = 50;
        um['C'] = 100;
        um['D'] = 500;
        um['M'] = 1000;
        int total = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
                total += (um[s[i + 1]] - um[s[i]]);
                ++i;
            }
            else if (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
                total += (um[s[i + 1]] - um[s[i]]);
                ++i;
            }
            else if (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
                total += (um[s[i + 1]] - um[s[i]]);
                ++i;
            }
            else {
                total += um[s[i]];
            }
        }
        return total;
    }
};