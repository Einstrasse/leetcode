# 0006. Zigzag Conversion

[https://leetcode.com/problems/zigzag-conversion/](https://leetcode.com/problems/zigzag-conversion/)    

## My Solution
솔직히 좀 귀찮은 문제인거같은데, 인내심을 갖고 구현해보았다. column 단위로 string을 잘라서 보관한 뒤, row 단위로 다시 한땀한땀 입력하는 방식으로 구현했다.


### Time Complexity
string length를 L라 하고 row num을 R라 할때,
worst case에선 O(L^2)
worstcase는 L = R인 경우이다.

### Space Complexity
O(L)

## Better Solution
그냥 가로 row 개수만큼 배열 만들고, 그때그때 그냥 append 하는 방식으로 simulation하면 쉽게 만든다...?!
https://leetcode.com/problems/zigzag-conversion/discuss/3403/Easy-to-understand-Java-solution
```java
public String convert(String s, int nRows) {
    char[] c = s.toCharArray();
    int len = c.length;
    StringBuffer[] sb = new StringBuffer[nRows];
    for (int i = 0; i < sb.length; i++) sb[i] = new StringBuffer();
    
    int i = 0;
    while (i < len) {
        for (int idx = 0; idx < nRows && i < len; idx++) // vertically down
            sb[idx].append(c[i++]);
        for (int idx = nRows-2; idx >= 1 && i < len; idx--) // obliquely up
            sb[idx].append(c[i++]);
    }
    for (int idx = 1; idx < sb.length; idx++)
        sb[0].append(sb[idx]);
    return sb[0].toString();
}
```
```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> vs(numRows, "");
        int n = s.length(), i = 0;
        while (i < n) {
            for (int j = 0; j < numRows && i < n; j++)
                vs[j].push_back(s[i++]);
            for (int j = numRows - 2; j >= 1 && i < n; j--)
                vs[j].push_back(s[i++]);
        }
        string zigzag;
        for (string v : vs) zigzag += v;
        return zigzag;
    } 
};
```