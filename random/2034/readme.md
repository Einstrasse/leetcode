# 2034. Stock Price Fluctuation 

[https://leetcode.com/problems/stock-price-fluctuation/](https://leetcode.com/problems/stock-price-fluctuation/)    

## My Solution
Using two type of data structure, one ordered_map and two priority_queue. Ordered_map store data real stock price for each timestamp. Key is timestamp and value is stock price. As it is ordered data structure, getting recent value is so simple.

To get minimum and maximum value, I utilized priority_queue. Priority queue stores data pair (price, timestamp). In order to get the maximum value, pop single value from maxium priority queue and compare data with stored in map. Because priority queue is not able to update which is not placed on edge, checking process is required. If value is not correct (updated or corrected), discard the value. Getting minimum and maximum value, in worst case it takes O(NlgN) time complexity, it is reasonable to compute in proper time.


### Time Complexity
Number of action = N.
Worst case, time complexity is O(NlgN)

### Space Complexity
O(N)

## Better Solution
Optimal solution looks like mine.