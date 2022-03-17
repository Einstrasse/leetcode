class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> colstr;
        vector<int> pattern;
        pattern.push_back(numRows);
        for (int i=0; i < numRows - 2; i++) {
            pattern.push_back(1);
        }
        int index = 0;
        int p = 0;
        for (int l = index + pattern.front(); index < s.length(); ) {
            colstr.push_back(s.substr(index, pattern[p]));
            
            l += pattern[p];
            index += pattern[p];
            p = (p+1) % pattern.size();
        }
        string ret = "";
        for (int i=0; i< numRows; i++) {
            for (int j=0; j < colstr.size(); j++) {
                string cols = colstr[j];
                int p = pattern[j % pattern.size()];
                if (p == numRows) {
                    if (i < cols.size()) {
                        ret += cols[i];
                    }
                } else {
                    if (numRows - 1 - (j % pattern.size()) == i) {
                        ret += cols[0];
                    }
                }
            }
        }
        return ret;
    }
};