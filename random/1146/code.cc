class SnapshotArray {
private:
    map<int, int> temp_data;
    vector<vector<pair<int, int>>> persistent_data;
    int snap_id;
    const int UNINITIALIZED = 0;
    
public:
    SnapshotArray(int length) {
        snap_id = 0;
        persistent_data.clear();
        persistent_data.reserve(length);
        for (int i=0; i < length; i++) {
            vector<pair<int, int>> item;
            item.push_back(make_pair(0, 0));
            persistent_data.push_back(item);
        }
    }
    
    void set(int index, int val) {
        temp_data[index] = val;
    }
    
    int snap() {
        for (auto item = temp_data.begin(); item != temp_data.end(); item++) {
            int index = item->first;
            int value = item->second;
            persistent_data[index].push_back(make_pair(snap_id, value));
        }
        temp_data.clear();
        
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        auto& arr = persistent_data[index];
        int l = 0;
        int r = arr.size(); // [l, r)
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (arr[m].first <= snap_id) {
                l = m;
            } else {
                r = m;
            }
        }
        return arr[l].second;
    }
};
/*
Snapshot
temp_data : temporary data written by set function, but snap function is not called. (map datastructure)
stored_data : persistent data written by snap function. (map datastructure)
get should return index value with stored largest snapshot id which is snapshot id is smaller than or equal to queried snapshot id.
*/

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */