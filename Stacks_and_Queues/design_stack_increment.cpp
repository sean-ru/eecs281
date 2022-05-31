#include <iostream>
#include <vector>
class CustomStack {
public:
    std::vector<int> arr;
    int stack_size;
    
    CustomStack(int maxSize) {
        stack_size = maxSize;
    }
    
    void push(int x) {
        if (arr.size() < stack_size) {
            arr.push_back(x);
        }
    }
    
    int pop() {
        if (arr.size() == 0) {
            return -1;
        }
        int temp = arr.back();
        arr.pop_back();
        return temp;
    }
    
    void increment(int k, int val) {
        int n = std::min(k, (int) arr.size());
        for (int i = 0; i < n; ++i) {
            arr[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */