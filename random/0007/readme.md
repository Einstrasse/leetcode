# 0007. Reverse Integer

[https://leetcode.com/problems/reverse-integer/](https://leetcode.com/problems/reverse-integer/)    

## My Solution
솔직히 개짜증나는 문제다..ㅡㅡ 64비트 정수는 써도 안된다고 함. 그래서 약간 애매한거 있어서 32bit unsigned로 사용해서 풀어보았다.
Overflow check하는게 컴파일에 되어 있어서 곱하기 전에 Overflow를 한번 체크를 해야 한다. ㅡㅡ
모듈러하고 / 10 해서 거꾸로 할려고 했는데, 이게 음수인 경우에는 더 더럽다. 그래서 음수를 양수로 바꾼 뒤 체크를 해야 하는데 음수는 범위가 1이 더 넓기 때문에 unsigned로 바꿔서 했다.

### Time Complexity
O(log10(N))

### Space Complexity
O(1)

## Better Solution
하 이런문젠 좀 안나왔으면...
```
reversed = reversed * 10 + x % 10;
```
아래와 같은 방식이 더 편해보인다. 근데 overflow check를 또 해줘야한다.