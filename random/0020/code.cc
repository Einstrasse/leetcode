class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            switch (c) {
                case '(':
                    stk.push('(');
                    break;
                case ')':
                    if (stk.size() && stk.top() == '(') stk.pop();
                    else return false;
                    break;
                case '{':
                    stk.push('{');
                    break;
                case '}':
                    if (stk.size() && stk.top() == '{') stk.pop();
                    else return false;
                    break;
                case '[':
                    stk.push('[');
                    break;
                case ']':
                    if (stk.size() && stk.top() == '[') stk.pop();
                    else return false;
                    break;
            }
        }
        return stk.empty();
    }
};