# 0146. LRU Cache

[https://leetcode.com/problems/lru-cache/](https://leetcode.com/problems/lru-cache/)

쉬울줄 알았는데 생각보다 오래 걸렸다. `O(1)`를 맞추는게 좀 빡셋고, Linked List C++ STL을 사용할 줄 몰라서 직접 Doubly Linked List를 구현하다가 많은 시간을 좀 소비한 것 같다.
결국 STL을 사용하니 좀 간편하게 구현할 수 있었다. Last element를 찾는데에 `rbegin()`을 사용하면 `list<int>::iterator`가 아닌 `list<int>::reverse_iterator`가 리턴된다는 점에서 컴파일 에러를 유발했다.