# 0068. Text Justification

[https://leetcode.com/problems/text-justification/](https://leetcode.com/problems/text-justification/)    

## My Solution
문자열 총 길이, 문자열 간 최소 공백 길이를 이용해서 단어 개수를 일단 배분하고, blank의 경우 나눠서 분배하되 나누어 떨어지지 않으면 1씩 더 분배하는 방식으로 하면 중간 정렬은 잘 된다.
근데 왼쪽 정렬부분에서 실수를 좀 했고 RLE encoding같은 부분에서 잘못 continue를 넣은 부분에서 실수를 조금 했다.

### Time Complexity
O(S*M)

### Space Complexity
O(N)

## Better Solution
1. 단어 하나면 그냥 단어 하나 두고 뒤에 공백 둔다.
2. 마지막 라인은 왼쪽 정렬이니 그냥 하나짜리 space로 구분하면 된다.
3. 그외에는 길이를 계산해서 나누고, 나누어 떨어지지 않으면 하나를 추가 하면 된다.