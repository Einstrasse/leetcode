# 2096. Step-By-Step Directions From a Binary Tree Node to Another

[https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/](https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/)    

## My Solution

재귀로 각 node를 찾은 뒤, Common Ancestor를 reduce한 뒤, start -> LCA -> end로 돌아가는 방식으로 구현해보았다. Time Complexity는 완탐해도 상관없어보여서 개꿀.
Audit으로 버그를 찾았는데 이게 핵심인듯.


### Time Complexity
O(N)

### Space Complexity
O(N)

## Better Solution
나는 경로에 node value도 같이 기입했는데, 어차피 같은 root node에서 출발할거니, node value를 기입 안하고 경로만 기입해도 된다..!!