# 0042. Trapping Rain Water

[https://leetcode.com/problems/trapping-rain-water/](https://leetcode.com/problems/trapping-rain-water/)

꽤나 오래 고민했는데 어려운 문제였다. Fenwick tree같은 자료구조로 range add를 해버리는 그런 문제인줄 알았는데, 결국 힌트를 보고 monotonic stack이라는 걸 적용해서 고민한 끝에 문제를 풀긴 풀었다.

스택을 이용해서 기둥 높이가 낮아지는 경우에만 깔고, 기둥 높이가 높아지는 경우 물이 고일 수 있는 양을 계산해서 더하는 방식으로 문제를 풀이했다.
신기하게도 인터뷰 식으로 연습하고 고민하다 보니, 코드의 오류를 실행하지 않고도 알아낼 수 있었다. 하지만 물의 양 계산하는 방식에서 왼쪽 기둥을 기준으로 해야 하는데, 이 부분에 사소한 실수로 TC하나를 날려먹고 결국 Solve하였다.

## Better.cc
google former interview 페이지에서 동일한 문제를 확인했는데, 놀랍게도 모노토닉 스택을 쓰지 않고 훨씬 더 쉽게도 풀 수 있었다.
최대값 최소값만 가지고도 구할 수 있었다..
시간복잡도: O(N)
공간복잡도: O(N)