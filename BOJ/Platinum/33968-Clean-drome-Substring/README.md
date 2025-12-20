## [[BOJ 33968] 클-린드롬 부분 문자열 (Clean-drome Substring)](https://www.acmicpc.net/problem/33968)

> **Topic:** String, Hashing, Manacher's  
> **Difficulty:** Platinum 4

### Complexity Analysis
* **Time Complexity:** $O(n^2 \log n)$
* **Space Complexity:** $O(n)$
*(Where $n$ is the length of the string)*

### Mistakes & Lessons
**Lesson:** The partial sum of a **Harmonic Series** is approximately $\ln(n)$. 
This provides the mathematical basis for why the complexity $O(\sum_{i=1}^{n} \frac{n}{i})$ results in $O(n \log n)$.

---
