# 0719. Find K-th Smallest Pair Distance

[https://leetcode.com/problems/find-k-th-smallest-pair-distance/](https://leetcode.com/problems/find-k-th-smallest-pair-distance/)    

## My Solution
Parametric search with transforming problem. M보다 distance가 작은 녀석들의 개수의 함수로 바이너리 서치를 하면 된다.

### Time Complexity
N은 num의 최대값
M은 num의 개수
O(NlgN * lgM)
### Space Complexity
O(1)
## Better Solution
내 솔루션이랑 비슷하지만 parametric 함수를 조지는 부분이 더 simple하고 optimized되어 있다. 똑같이 해당 m에 대해 쿼리하면서 m보다 거리가 작은 녀석들의 개수를 cnt로 찾아서 파라메트릭 서치를 한다.
```java
public int smallestDistancePair(int[] nums, int k) {
    Arrays.sort(nums);
    
    int n = nums.length;
    int l = 0;
    int r = nums[n - 1] - nums[0];
    
    for (int cnt = 0; l < r; cnt = 0) {
        int m = l + (r - l) / 2;
        
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && nums[j] <= nums[i] + m) j++;
            cnt += j - i - 1;
        }
        
        if (cnt < k) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    
    return l;
}
```