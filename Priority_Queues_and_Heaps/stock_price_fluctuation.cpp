#include <iostream>
#include <map>
#include <unordered_map>
class StockPrice {
private:    
    int present_timestamp;
    std::unordered_map<int, int> map;
    std::map<int, int> ordered_map;
    
public:
    StockPrice()
        : present_timestamp(0)
        {}
    
    void update(int timestamp, int price) {
        if (map.count(timestamp)) {
            ordered_map[map[timestamp]] -= 1;
            if (!ordered_map[map[timestamp]]) {
                ordered_map.erase(map[timestamp]);
            }
        }
        present_timestamp = std::max(present_timestamp, timestamp);
        map[timestamp] = price;
        ordered_map[price] += 1;
    }
    
    int current() {
        return map[present_timestamp];
    }
    
    int maximum() {
        return ordered_map.rbegin()->first;
    }
    
    int minimum() {
        return ordered_map.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */