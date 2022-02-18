class Solution {
public:
    string minRemoveToMakeValid(string s) {
        /*
        Condition to valid parenthesis.
        1. Number of left and right parenthesis should be equal
        2. Each parenthesis should be paired.
        3. For each pair, left parenthesis should be placed smaller index. 
        
        Invalid case
        1. Number of parenthesis is not equal.
            1.1. Left parenthe is more
            1.2. Right parenthesis is more.
        2. Position of parenthesis is inversed.
        
        
        Simple naive algorithm with stack.
        scanning string from left to right.
        If scanner meet alphabet, it pass to result string.
        If scanner meet a left parentehsis, push index of left parenthesis to stack.
        If scanner meet a right parenthesis, if stack is not empty, pop a item, otherwise, ignore right parenthesis. (right more)
        If scanner finishes with stack containing contents. (Left more)
        */
        stack<int> stk;
        vector<int> ignores;
        for (size_t i=0; i < s.length(); i++) {
            char c = s[i];
            if (c >= 'a' && c <= 'z') continue; //pass for alphabet
            else if (c == '(') {
                stk.push(i);
            } else if (c == ')') {
                if (stk.size()) {
                    stk.pop();
                } else {
                    ignores.push_back(i); //ignore right more cases
                }
            }
        }
        while (stk.size()) { //ignore left more cases
            ignores.push_back(stk.top());
            stk.pop();
        }
        
        //Rebuild string exclude ignored index chars.
        sort(ignores.begin(), ignores.end());
        string res = "";
        int j = 0;
        for (size_t i=0; i < s.length(); i++) {
            if (j < ignores.size() && ignores[j] == i) {
                j++;
                continue;
            }
            res += s[i];
        }
        return res;
    }
};