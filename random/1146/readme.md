# 1146. Snapshot Array

[https://leetcode.com/problems/snapshot-array/](https://leetcode.com/problems/snapshot-array/)    

## My Solution
snap_shot의 개념을 햇갈려서 문제 접근 자체를 조금 잘못한 부분이 있었다. 바뀌는 부분만 snap 시에 저장하면 된다는 점은 공통적으로 되는 부분이긴 한데,
안바뀐 부분의 경우 가장 최근 snap_id에서 값을 가져오면 된다는 점을 잘 체크했어야 했다. snap_id는 get할 때 실질적으로 snap_id보다 작거나 같은 것 중에 최대값의 값을 가져오면, 즉 최신 값을 가져오면 된다는 점을 이용해서 바이너리 서치를 실시했다.


### Time Complexity
Operation마다 다른데,
Init = O(length)
Set = O(lgN) 여기서 N은 이미 set된 녀석들의 개수
Snap = O(N) 여기서 이미 set된 녀석들의 개수
Get = O(lgsnapNum) 해당 index에 snapshot 개수가 snapNum이다.

### Space Complexity
Operation Number를 N이라고 하면
O(N+L)

## Better Solution
Binary Search를 직접 구현하지 않고, upper_bound를 구한 뒤 -1를 하는 식으로 <=의 최대값을 구할 수 있나보다.
lower_bound는 해당 값보다 같거나 큰 값 중 최소값이고, upper_bound는 해당 값보다 큰 값 중 최소값이다.
큰 값 중 최소값 보다 하나 작은 값은 같거나 작은 값이 되나 보다.