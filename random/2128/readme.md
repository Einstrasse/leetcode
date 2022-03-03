# 2128. Remove All Ones With Row and Column Flips

[https://leetcode.com/problems/remove-all-ones-with-row-and-column-flips/](https://leetcode.com/problems/remove-all-ones-with-row-and-column-flips/)    

## My Solution
The operation has several properties.
The order of operation does not matter.
-> it means, for each row and column there are only two option, do operation or not.
If just performing row-level operation, make column uniform, it is possible to remove all '1'.
Making column-level uniform can be achived by just performing row-level operation.
Row-level operation option is decided by just single column. When set any random column uniform, then all columns are uniform, it is possible otherwise it is impossible.

### Time Complexity
O(NM)
It costs for check all items

### Space Complexity
O(N)

## Better Solution
Just compare first row and others same pattern or negation pattern...
```python
class Solution:
    def removeOnes(self, grid: List[List[int]]) -> bool:
        r1, r1_invert = grid[0], [1-val for val in grid[0]]
        for i in range(1, len(grid)):
            if grid[i] != r1 and grid[i] != r1_invert:
                return False
        return True
```