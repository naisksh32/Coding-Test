# 바이러스
##### 난이도: ***S3***
##### Link: https://www.acmicpc.net/problem/2606
##### Tag: 그래프이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색
##### 풀이 일자: 2025년 10월 12일
***
## 문제 탐색하기
컴퓨터가 감염되는 경로를 그래프로 나타내고, 이를 코드상으로 옮겨서 탐색 진행

### 해결요소
1. 그래프 구현  
    - 인접 행렬: 전체적인 구조를 파악 가능, 2차원 리스트로 T/F 뿐만 아니라 사이 관계까지 설정 가능
    - 인접 리스트: 어디서 어디로 가는지 보기 편함, 방향성을 잘 따질 수 있음
    - 단방향, 양방향 주의하기!!
    - 문제에선 작은 숫자부터 탐색해야 함으로 정렬 필수!

2. BFS 구현
    - 너비 우선 탐색: 큐 자료형으로 노드를 입력 받고, 먼저 입력받은 노드부터 탐색
    - 해당 노드가 갈 수 있는 모든 노드를 큐에 저장하고, 먼저 들어온 노드부터 순차적으로 진행
    - 큐가 빌 때까지 탐색 진행
***
## 코드 설계하기
```
# 그래프 구현
N = int(key_in())
R = int(key_in())
graph = [[0]*N for _ in range(N)]
for i in range(R):
    s, e = map(int, key_in().split())
    # 양방향 그래프
    graph[s-1][e-1] = 1
    graph[e-1][s-1] = 1
----------------------------------------------------
# BFS 탐색 방식으로 구현
from collections import deque

q = deque()
visited = set()

q.append(1)
visited.add(1)

while q:
    node = q.popleft()
    
    for i in range(len(graph[node-1])):
        if graph[node-1][i] == 1 and (i+1) not in visited:
            q.append(i+1)
            visited.add(i+1)
            
            
print(len(visited)-1)

```
### ★★★시간 복잡도★★★
##### O(N^2)
주어진 그래프의 노드 가로, 세로를 모두 탐색(정방행렬 탐색)

***
## 시도 회차 수정사항
- 그래프 구현중 양방향 구현, 양쪽 모두 true
- BFS 방식으로 감염된 컴퓨터 갯수 구하기

***
## 정답 코드
```
# 표준 입력
import sys

key_in = lambda: sys.stdin.readline().rstrip()

N = int(key_in())
R = int(key_in())
graph = [[0]*N for _ in range(N)]
for i in range(R):
    s, e = map(int, key_in().split())
    graph[s-1][e-1] = 1
    graph[e-1][s-1] = 1

# BFS 탐색 방식으로 구현
from collections import deque

q = deque()
visited = set()

q.append(1)
visited.add(1)

while q:
    node = q.popleft()
    
    for i in range(len(graph[node-1])):
        if graph[node-1][i] == 1 and (i+1) not in visited:
            q.append(i+1)
            visited.add(i+1)
            
            
print(len(visited)-1)
```