class Node {
public:
    Node* prev, *next;
    int key;
    Node(int key) {
        prev = next = nullptr;
        this->key = key;
    }
};

class LRUCache {
public:
    unordered_map<int, pair<int, list<int>::iterator>> mp; // mp[key] = make_pair(value, linked_list_ptr);
    list<int> ls; //key를 저장
    int capa;
    LRUCache(int capacity) {
        capa = capacity;
        ls.clear();
        mp.clear();
        mp.reserve(capacity * 2);
    }
    
    void accessCache(int key) {
        list<int>::iterator ptr = mp[key].second;
        ls.erase(ptr);
        ls.push_back(key);
        
        mp[key].second = --ls.end();
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        } else {
            //update access timing linked list
            accessCache(key);
            
            return mp[key].first;
        }
    }
    
    void put(int key, int value) {
        if (mp.find(key) == mp.end()) { //key not existing
            //adding new key
            ls.push_back(key);
            mp[key] = make_pair(value, --ls.end());
            
            // cache eviction
            if (ls.size() > capa) {
                int victim_key = *ls.begin();
                mp.erase(victim_key);
                ls.erase(ls.begin());
            }
            
        } else {
            //updating existing key
            mp[key].first = value;
            accessCache(key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
