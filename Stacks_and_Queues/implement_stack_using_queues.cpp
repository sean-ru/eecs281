#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> s1, s2;
public:
    MyQueue() {

    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int s = s2.top();
        s2.pop();
        return s;
    }
    
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int s = s2.top();
        return s;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
int main(int argc, char** argv) {
    exit(0);
}