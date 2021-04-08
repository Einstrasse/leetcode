#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> index;
        int start = -1;
        int ans = 0;
        for (size_t end=0; end < s.length(); end++) {
            char cur = s[end];
            if (index.find(cur) != index.end() && start < index[cur]) {
                start = index[cur];
            }
            index[cur] = end;
            if (end - start > ans) {
                ans = end - start;
            }
        }
        return ans;
    }
};
