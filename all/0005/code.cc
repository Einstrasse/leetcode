class Solution {
public:
    bool isPalindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        for (int l = s.length(); l > 0; l--) {
            for (int i=0; i + l <= s.length(); i++) {
                if (isPalindrome(s, i, i+l-1)) {
                    return s.substr(i, l);
                }
            }
        }
        return s.substr(0,1);
    }
};
