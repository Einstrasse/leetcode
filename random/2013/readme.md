# 2013. Detect Squares

[https://leetcode.com/problems/detect-squares/](https://leetcode.com/problems/detect-squares/)    

## My Solution
정사각형이 아니라 직사각형 찾기인줄알고 조건을 잘못 봐서 계속 개 해맸다. 이러면 그냥 조질듯 ㅠ
중복 점 갯수 세는거랑, 축 단위로 저장하는 것 이 두가지를 잘 봐야 할 것 같다.

### Time Complexity
add: O(1)
count: O(T)
T <= 1000 이므로 풀만함..
### Space Complexity
O(T)

## Better Solution
비슷함..ㅎ 그냥 간단하게 이차원 array랑 pair 배열로도 풀 수 있음.