# 0020. Valid Parentheses

[https://leetcode.com/problems/valid-parentheses/](https://leetcode.com/problems/valid-parentheses/)    

## My Solution
하 Easy문제라고 대충 생각하고 문제 Definition을 제대로 고려 안해서 이상하게 틀렸다 ㅡㅡ.
괄호 종류가 세가지가 나온다는 점이랑, 닫히는거는 `{(})` 처럼 크로스오버가 되면 안된다는 점 때문에 변수 3개로 해볼려다가 해멤
Context-Free-Grammer의 특징 그대로 가져가고 있다.

그리고 stack top을 보는 것도 size 체크를 안해서 틀리고 그랬다 하~!?

### Time Complexity
O(N)
### Space Complexity
O(N)

## Better Solution
ㅋㅋ 오른쪽괄호를 넣고 더 심플하게 구현이 가능했다..으어...
```java
public boolean isValid(String s) {
	Stack<Character> stack = new Stack<Character>();
	for (char c : s.toCharArray()) {
		if (c == '(')
			stack.push(')');
		else if (c == '{')
			stack.push('}');
		else if (c == '[')
			stack.push(']');
		else if (stack.isEmpty() || stack.pop() != c)
			return false;
	}
	return stack.isEmpty();
}
```