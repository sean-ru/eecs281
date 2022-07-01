#include <iostream>
#include <unordered_map>
using namespace std;

class MyHashMap {
public:
    unordered_map<int, int> m;

    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.end()) {
            m[key] = value;
        }
        else {
            pair<int, int> item = make_pair(key, value);
            m.insert(item);
        }
    }
    
    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) {
            return -1;
        }
        return m[key];
    }
    
    void remove(int key) {
        auto it = m.find(key);
        if (it != m.end()) {
            m.erase(key);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */