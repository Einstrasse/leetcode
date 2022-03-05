typedef pair<int, int> pii;

class StockPrice {
private:
    map<int, int> mp;
    priority_queue<pii> maxheap, minheap;
public:
    StockPrice() {
        mp.clear(); // mp[timestamp] = price;  always correct value
        while(maxheap.size()) maxheap.pop();
        while(minheap.size()) minheap.pop();
        // make_pair(price, timestamp); lazy update
    }
    
    void update(int timestamp, int price) {
        mp[timestamp] = price;
        maxheap.push(make_pair(price, timestamp));
        minheap.push(make_pair(-price, timestamp));
    }
    
    int current() {
        auto it = mp.rbegin();
        return it->second;
    }
    
    int maximum() {
        while (maxheap.size()) {
            auto top = maxheap.top();
            if (mp[top.second] == top.first) {
                return top.first;
            } else {
                maxheap.pop();
            }
        }
        assert(false);
    }
    
    int minimum() {
        while(minheap.size()) {
            auto top = minheap.top();
            if (mp[top.second] == -top.first) {
                return -top.first;
            } else {
                minheap.pop();
            }
        }
        assert(false);
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