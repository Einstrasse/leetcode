# 0818. Race Car

[https://leetcode.com/problems/race-car/](https://leetcode.com/problems/race-car/)    

## My Solution
이진수로 생각했을때, 111111 과 같은 연속된 2진수 자연수를 더하거나 빼는 방식으로 수를 만든다는 점으로, 모든 정수는 반드시 만들 수 있다는 점과
Input 범위를 생각했을때 reasonable한 시간 내에 시뮬레이션 해서 만들어낼 수 있다는 점을 알아낼 수 있다.
그런데 이렇게그냥 naive하게 만드는 것이 optimal이라는 보장은 없다. 그런 부분에서 오류를 범해서 생각이 좀 꼬였다.
그리고 양수로 갈 거면 음수 공간을 궂이 방문할 필요가 없다는 것도 하나의 intuition인 듯. 왜냐면 연속된 이진수들의 합으로 숫자를 나타낼 수 있는데, 합하는 순서는 중요하지 않기 때문에.

BFS처럼 탐색하되 memoization을 적용하는 방식으로(dynamic programming) 문제를 해결할 수 있었다.


### Time Complexity
Average case는 모르겠고, worst case에서 T를 target 값의 max값이라 했을때 O(TlgT) 이다.

### Space Complexity
T를 target 값의 max값이라 했을 때, O(TlgT)

## Better Solution
