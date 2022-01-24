class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& lhs, vector<int>& rhs) {
            return lhs[0] < rhs[0]; //sorting ascending order
        });
        vector<vector<int>> ans;
        int s = intervals[0][0];
        int e = intervals[0][1];
        for (int i=1; i < intervals.size(); i++) {
            int cs = intervals[i][0];
            int ce = intervals[i][1];
            if (cs <= e) {
                //overlapping case
                e = max(e, ce);
            } else {
                //not overlapping case
                vector<int> tmp;
                tmp.push_back(s);
                tmp.push_back(e);
                ans.push_back(tmp);
                s = cs;
                e = ce;
            }
        }
        vector<int> tmp;
        tmp.push_back(s);
        tmp.push_back(e);
        ans.push_back(tmp);
        return ans;
    }
};