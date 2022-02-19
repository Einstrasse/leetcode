class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> empty;
        if (changed.size() & 1) {
            return empty;
        }
        multiset<int> s;
        for (int item : changed) {
            s.insert(item);
        }
        vector<int> ans;
        while (s.size() >= 2) {
            auto first = s.begin();
            int fval = *first;
            s.erase(first);
            ans.push_back(fval);
            auto second = s.find(fval * 2);
            if (s.end() == second) {
                return empty;
            } else {
                s.erase(second);
            }
            
        }
        return ans.size() == changed.size() / 2 ? ans : empty;
    }
};