# [Gold IV] Walking Home - 23880 

[문제 링크](https://www.acmicpc.net/problem/23880) 

### 성능 요약

메모리: 2024 KB, 시간: 1184 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2023년 11월 2일 11:08:41

### 문제 설명

<p>Bessie the cow is trying to walk from her favorite pasture back to her barn.</p>

<p>The pasture and farm are on an $N \times N$ grid ($2 \leq N \leq 50$), with her pasture in the top-left corner and the barn in the bottom-right corner. Bessie wants to get home as soon as possible, so she will only walk down and to the right. There are haybales in some locations that Bessie cannot walk through; she must walk around them.</p>

<p>Bessie is feeling a little tired today, so she wants to change the direction she walks at most $K$ times ($1 \leq K \leq 3$) .</p>

<p>How many distinct paths can Bessie walk from her favorite pasture to the barn? Two paths are distinct if Bessie walks in a square in one path but not in the other.</p>

### 입력 

 <p>The input for each test case contains $T$ sub-test cases, each describing a different farm and each of which must be answered correctly to pass the full test case. The first line of input contains $T$ ($1 \leq T \leq 50$). Each of the $T$ sub-test cases follow.</p>

<p>Each sub-test case starts with a line containing $N$ and $K$.</p>

<p>The next $N$ lines each contain a string of $N$ characters. Each character is either <code>.</code> if it is empty or <code>H</code> if it has a haybale. It is guaranteed the top-left and bottom-right corners of the farm will not contain haybales.</p>

### 출력 

 <p>Output $T$ lines, the $i$th line containing the number of distinct paths Bessie can take in the $i$th sub-test case.</p>

