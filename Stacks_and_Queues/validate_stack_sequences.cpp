#include <iostream>
#include <vector>
#include <stack>
class Solution {
public:
    bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped) {
        int length = pushed.size();
        std::stack<int> myStack;
        
        int j = 0;
        for (int i = 0; i < length; ++i) {
            myStack.push(pushed[i]);
            while (!myStack.empty() && j < length && myStack.top() == popped[j]) {
                myStack.pop();
                ++j;
            }
        }
        return myStack.empty();
    }
};