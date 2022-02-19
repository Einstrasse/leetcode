# 2007. Find Original Array From Doubled Array

[https://leetcode.com/problems/find-original-array-from-doubled-array/](https://leetcode.com/problems/find-original-array-from-doubled-array/)    

## My Solution
나름 쉬운문제이고 multiset을 쓰면 그냥 되는데, 0의 경우를 제대로 체크를 안해서(boundary condition check) 좀 에러가 났다. ㅜㅡㅜ
순서가 중요하지 않기 때문에 multiset에 다 집어넣고 첫번째 항이 가장 작은 값일 것이기 때문에 그거 곱하기2한 값이 있으면 하나씩 제거하는 방식으로 풀어보았다.
그런데 0의 경우는 2배 한 값도 같은 값을 가리킬 수 있고, 포인터 두개를 구해놓고 두개를 둘다 삭제하면 Heap 내부구조에서 꼬일 수 있으므로 하나하나 포인터를 get한 뒤 삭제 해야한다.
그리고 erase함수에 value를 넣으면 같은 value값들이 한꺼번에 삭제되기 때문에 find한 뒤 delete를 해야 한다.


### Time Complexity
O(NlgN)

### Space Complexity
O(N)

## Better Solution
모든 정수가 positive라는 가정 같은것도 중요한 듯 하다. 0은 별도로 체크하는 방식을 이용했다.
unordered_map을 쓰면 기본값이 0으로 체크가 되는 것 같다. array for-loop 방식도 좋아보인다.
[https://leetcode.com/problems/find-original-array-from-doubled-array/discuss/1470959/JavaC%2B%2BPython-Match-from-the-Smallest-or-Biggest-100](https://leetcode.com/problems/find-original-array-from-doubled-array/discuss/1470959/JavaC%2B%2BPython-Match-from-the-Smallest-or-Biggest-100)

```c++
vector<int> findOriginalArray(vector<int>& A) {
    if (A.size() % 2) return {};
    unordered_map<int, int> c;
    for (int a : A) c[a]++;
    vector<int> keys;
    for (auto it : c)
        keys.push_back(it.first);
    sort(keys.begin(), keys.end(), [](int i, int j) {return abs(i) < abs(j);});
    vector<int> res;
    for (int x : keys) {
        if (c[x] > c[2 * x]) return {};
        for (int i = 0; i < c[x]; ++i, c[2 * x]--)
            res.push_back(x);
    }
    return res;
}
```
다만 위의 방식은 A.size()를 짝수인지 체크하는 로직이 없으면, key가 0인 경우 같은 배열을 reference하기 때문에 좀 위험한 부분들이 있는 것 같다.
pass는 나옴.