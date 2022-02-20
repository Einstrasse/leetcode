# 0833. Find And Replace in String

[https://leetcode.com/problems/find-and-replace-in-string/](https://leetcode.com/problems/find-and-replace-in-string/)    

## My Solution

Replacement라는 구조체를 만들어서 한번에 매칭되는지를 다 체크한 뒤, 한꺼번에 string을 더해서 만들어낸다. Replacement가 index가 정렬되어 입력이 들어온다고 가정해서 한번 틀렸다. ㅠ
Condition을 잘 체크해야 할 듯 확실히!

### Time Complexity
O(NlgN)

### Space Complexity
O(N)

## Better Solution
길이가 달라진다는 점이 핵심인 부분인데, 오른쪽에서 왼쪽으로 replacement를 하면 상관이 없게 된다..??!
왼쪽에서 오른쪽으로 하더라도 길이를 체크하면서 하면 상관이 없긴 하다. 소팅을 잘 해야함.
```c++
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<pair<int, int>> sorted;
        for (int i = 0 ; i < indexes.size(); i++)
            sorted.push_back({indexes[i], i});
        sort(sorted.rbegin(), sorted.rend());
        for (auto ind : sorted) {
            int i = ind.first;
            string s = sources[ind.second], t = targets[ind.second];
            if (S.substr(i, s.length()) == s)
                S = S.substr(0, i) + t + S.substr(i + s.length());
        }
        return S;
    }
```