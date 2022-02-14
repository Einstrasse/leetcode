# 0719. Find K-th Smallest Pair Distance

[https://leetcode.com/problems/find-k-th-smallest-pair-distance/](https://leetcode.com/problems/find-k-th-smallest-pair-distance/)

20번째 라인 조건이랑, lower_bound 구현하는 부분에서 좀 해멨다. lower_bound는 both inclusive range를 정의하고, right를 리턴하는 방식으로 하고, left를 하나씩 전진시키니 생각보다 간단했다.
20번째 라인 조건은 adjacent pair가 이미 M보다 클 수 있다는 점을 체크를 해줘야 했다.

Parametric search로 문제를 변환하여 해결을 했고, 파라메트릭 서치할 때 마다 조건은 distance가 M보다 작은 것의 개수를 f(M)으로 쿼리했다.

Time Complexity는 `nums[i]`의 최대값이 `M`, `nums.length == N`이라고 할 때 `O(NlgN + lgM * NlgN)`이니 즉 `O(lgM * NlgN)`이다.
Space Complexity는 `O(N)`이고 이건 주어진거를 Sorted array를 저장하는 정도이다.

# Reference
https://blog.naver.com/bestmaker0290/220820005454