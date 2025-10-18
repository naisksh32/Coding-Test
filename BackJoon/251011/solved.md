# DFS와 BFS
##### 난이도: ***S2***
##### Link: https://www.acmicpc.net/problem/1260
##### Tag: 그래프이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색
##### 풀이 일자: 2025년 10월 11일
***
## 문제 탐색하기
그림으로 표현된 그래프(문제에선 노드와 간선으로 표현)를 코드로 옮기고, 이를 DFS, BFS 방법으로 탐색하는 노드 순서에 대해 알아보자

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

3. DFS 구현
    - 깊이 우선 탐색: stack 자료형으로 노드를 입력받고, 나중에 입력받은 노드부터 탐색
    - 해당 노드가 탐색할 수 있는 곳 끝까지 탐색 후, 그 다음 노드 탐색 진행
    - 백트래킹 방법의 일종(재귀 함수로도 구현 가능)
***
## 코드 설계하기
```
# 그래프 구현
# 노드, 간선, 시작노드 입력받기
N, M, V = map(int, key_in().split())

# 인접리스트로 구현
near_list = [[] for _ in range(N)]

# 반복문을 통하여 각 간선을 입력받음
for _ in range(M):
    s, e = map(int, key_in().split())
    # ★ 양방향 연결 ★
    near_list[s-1].append(e)
    near_list[e-1].append(s)

# 노드를 순차적으로 정렬
for i in range(N):
    try:
        near_list[i].sort()

    # 만약 노드가 비어있으면 정렬 필요X
    except:
        continue
    
----------------------------------------------------
# BFS 너비 우선 탐색
def BFS():
    from collections import deque
    
    q = deque([V])      # BFS 탐색을 위한 queue 자료형
    visited = set([V])  # 방문점을 남기는 요소
    

    # 큐에 탐색할 장소가 남아있으면 반복
    while q:
        node = q.popleft()      # 제일 앞쪽 요소를 추출
        print(node, end=' ')    # 해당 노드 프린트

        # 해당 노드가 갈 수 있는 방향을 넓게 탐색
        for i in range(len(near_list[node-1])):
            
            # 만약 탐색한 노드가 아직 방문하지 않았더라면
            if near_list[node-1][i] not in visited:
                q.append(near_list[node-1][i])      # 다음 탐색 장소에 추가
                visited.add(near_list[node-1][i])   # 방문한 장소에도 추가
----------------------------------------------------
# DFS 깊이 우선 탐색
def DFS():
    stack = [V]     # 탐색을 위한 스택 자료형
    visited= [False for _ in range(N)]  # 방문 여부를 저장
    visited[V-1] = True # 첫 시작점은 방문
    
    # 재귀함수를 통한 DFS 구현
    def func():

        node = stack.pop()      # 스택에서 탐색할 노드를 추출
        print(node, end=' ')
        
        # 만약 탐색할 리스트가 비어있다면 함수 끝
        if not near_list[node-1]:
            return
        
        # 해당 노드부터 탐색 진행
        for i in range(len(near_list[node-1])):
            
            # 방문한 노드라면 다음 경우로
            if visited[near_list[node-1][i]-1]:
                continue
            
            stack.append(near_list[node-1][i])      # 다음 탐색에 추가
            visited[near_list[node-1][i]-1] = True  # 방문함 표시

            # 현재 탐색 노드 그 다음 노드로 재귀함수를 통한 탐색 진행
            func()
    
    func()  # DFS 탐색 시작

```
### ★★★시간 복잡도★★★
##### 인접 리스트: O(V+E) - BFS, DFS 모두
##### 인접 행렬: O(V^2) - BFS, DFS 모두

***
## 시도 회차 수정사항
- BFS는 많이 해서 쉽게 구현
- DFS는 백트래킹 방법을 통한 구현
- 그래프를 코드로 만드는 것에 집중!, 특히나 단방향, 양방향인지 구별 잘하기
***
## 정답 코드
```
# 표준 입력
import sys

key_in = lambda: sys.stdin.readline().rstrip()

N, M, V = map(int, key_in().split())

near_list = [[] for _ in range(N)]

for _ in range(M):
    s, e = map(int, key_in().split())
    near_list[s-1].append(e)
    near_list[e-1].append(s)

for i in range(N):
    try:
        near_list[i].sort()
    except:
        continue
    

# BFS 너비 우선 탐색
def BFS():
    from collections import deque
    
    # BFS 탐색을 위한 queue 자료형
    q = deque([V])
    # 방문점을 남기는 요소
    visited = set([V])
    
    # 큐에 탐색할 장소가 남아있으면 반복
    while q:
        # 제일 앞쪽 요소를 추출
        node = q.popleft()
        # 해당 노드 프린트
        print(node, end=' ')

        
        # 해당 노드가 갈 수 있는 방향을 넓게 탐색
        for i in range(len(near_list[node-1])):
            # 만약 탐색한 노드가 아직 방문하지 않았더라면
            if near_list[node-1][i] not in visited:
                q.append(near_list[node-1][i])      # 다음 탐색 장소에 추가
                visited.add(near_list[node-1][i])   # 방문한 장소에도 추가

# DFS 깊이 우선 탐색
def DFS():
    stack = [V]
    visited= [False for _ in range(N)]
    visited[V-1] = True
    
    def func():
        node = stack.pop()
        print(node, end=' ')
            
        if not near_list[node-1]:
            return
        
        for i in range(len(near_list[node-1])):
            
            if visited[near_list[node-1][i]-1]:
                continue
            
            stack.append(near_list[node-1][i])
            visited[near_list[node-1][i]-1] = True
            func()

    func()
        
        
DFS()
print()
BFS()

```