# 1293. Shortest Path in a Grid with Obstacles Elimination

[https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/](https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/)    

## My Solution

BFS를 하는데 state를 3차원으로 지정해서 좌표 및 남은 벽 부술수 있는 횟수로 묶어서 체크를 했다. 알고스팟문제랑 똑같다.


### Time Complexity
O(NMK)이니깐 O(N^2M^2)가 된다.

### Space Complexity
마찬가지로 O(NMK)이니깐 O(N^2M^2)가 된다.

## Better Solution
파이썬으로 푼 사람 보니, visit 배열을 set으로 했다. 그리고 dist를 state안에다가 넣어서 관리를 했다.
그리고 마지막 state에 도달하면 그냥 거기서 함수를 종료하고 리턴해버리는 방식으로 구현함. 중간에 리턴하는거를 왜 생각을 못햇지? 흠?