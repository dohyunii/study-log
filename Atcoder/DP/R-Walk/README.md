## [[Atcoder-dp_r] Walk](https://atcoder.jp/contests/dp/tasks/dp_r)

> **Topic:** Dynamic Programming, Graph Theory

### Complexity Analysis
* **Time Complexity:** $O(N^3\log(K))$
* **Space Complexity:** $O(N^2)$

### Mistakes & Lessons
**Lesson:** The value at row i and column j in A^k is exactly the number of distinct walks of length k from node i to node j.\
**Mistake:** Wrong calculation of modular operations. Might be useful to use mod template as it is faster.



---