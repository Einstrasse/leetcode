# 1249. Minimum Remove to Make Valid Parentheses

[https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/)    

## My Solution
스택을 이용한 Naive 2번 scan하는 ad-hoc 알고리즘을 작성해보았다. Context-Free-Grammer의 정석이라고 볼 수 있는 문제였다.    
Invalid의 index를 저장해놓고 나중에 지우기를 썼는데, 이러면 sorting을 한번 더 해줘야하는 단점이 있다.

## Better Solution
[https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/discuss/419402/JavaC%2B%2B-Stack](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/discuss/419402/JavaC%2B%2B-Stack)    
1) Stack and Placeholder
Invalid에 `*`같은 심볼로 바꿔놓고 나중에 repalce해서 지우는 방식이 훨씬 간단한듯 하다.

2) Stack with Tracking
아니면 Invalid의 index를 별도의 값으로 저장하는게 아니라, stack에다가 함께 사용해도 될 듯 하다.
스택으로 겸사 겸사 사용이 가능한 이유는,  `)` 때문에 push를 최근에 했다면 어차피 스택이 비어있다는 뜻이기 때문이다.
그래서 양수,음수로 `(`인지 `)`인지를 체크한 뒤, top의 값을 이용해서 `)`가 저장되었는지 `(` 가 저장되었는지를 체크하면 된다.