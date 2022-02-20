typedef struct _Replacement {
    int index;
    size_t length;
    string result;
    bool operator<(const struct _Replacement& rhs) const {
        return index < rhs.index;
    }
} Replacement;

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<Replacement> replacements;
        for (int i=0; i < indices.size(); i++) {
            if (s.substr(indices[i], sources[i].length()) == sources[i]) {
                replacements.push_back({indices[i], sources[i].length(), targets[i]});
            }
        }
        sort(replacements.begin(), replacements.end());
        string result = "";
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            if (j < replacements.size() && replacements[j].index <= i) {
                Replacement rep = replacements[j];
                result += rep.result;
                i += rep.length - 1;
                j++;
                continue;
            }
            result += s[i];
        }
        return result;
    }
};