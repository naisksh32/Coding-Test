# 결혼식
##### 난이도: ***S2***
##### Link: https://www.acmicpc.net/problem/5567
##### Tag: 그래프이론, 그래프 탐색, 너비 우선 탐색
##### 풀이 일자: 2025년 10월 12일
***
## 문제 탐색하기
결혼식의 초대 인원을 depth=2까지 탐색하여 도출하자

### 해결요소
1. 그래프 구현  
    - 인접 행렬: 전체적인 구조를 파악 가능, 2차원 리스트로 T/F 뿐만 아니라 사이 관계까지 설정 가능
    - 인접 리스트: 어디서 어디로 가는지 보기 편함, 방향성을 잘 따질 수 있음
    - 단방향, 양방향 주의하기!!
    - 문제에선 작은 숫자부터 탐색해야 함으로 정렬 필수!

2. DFS 구현
    - 깊이 우선 탐색: 한 노드가 탐색할 수 있는 노드 끝까지 탐색
    - stack 자료형과 재귀함수를 통해 구현
***
## 코드 설계하기
```
# 그래프 구현
n = int(key_in())
m = int(key_in())
graph = [[0]*n for _ in range(n)]
for _ in range(m):
    ai, bi = map(int, key_in().split())
    graph[ai-1][bi-1] = 1
    graph[bi-1][ai-1] = 1
----------------------------------------------------
# DFS 탐색 방식으로 구현
# DFS 변수 설정
s = []
visited = [False] * n
invite = set()

# DFS 초깃값 설정 (node 1 방문)
s.append(1)
visited[0] = True

def func(k):
    
    # depth를 2번 탔다 -> 함수 종료
    if k == 2:
        return
    
    node = s.pop()
    for i in range(len(graph[node-1])):
        if graph[node-1][i] == 1 and not visited[i]:
            s.append(i+1)
            visited[i] = True
            invite.add(i+1)
            func(k+1)
            visited[i] = False

func(0)
print(len(invite))
```
### ★★★시간 복잡도★★★
##### O(N^2)
주어진 그래프의 노드 가로, 세로를 모두 탐색(정방행렬 탐색)

***
## 시도 회차 수정사항
- 그래프 구현중 양방향 구현, 양쪽 모두 true
- DFS 방식으로 최대 깊이를 설정하고, 재귀함수로 구현
- BFS 방식으로는 저장하는 형식에 노드, 깊이 상태를 함께 저장, 이후 깊이가 2인 노드들만 추출

***
## 정답 코드
```
# 표준 입력
import sys

key_in = lambda: sys.stdin.readline().rstrip()

n = int(key_in())
m = int(key_in())
graph = [[0]*n for _ in range(n)]
for _ in range(m):
    ai, bi = map(int, key_in().split())
    graph[ai-1][bi-1] = 1
    graph[bi-1][ai-1] = 1


# DFS 변수 설정
s = []
visited = [False] * n
invite = set()

# DFS 초깃값 설정 (node 1 방문)
s.append(1)
visited[0] = True

def func(k):
    
    # depth를 2번 탔다 -> 함수 종료
    if k == 2:
        return
    
    node = s.pop()
    for i in range(len(graph[node-1])):
        if graph[node-1][i] == 1 and not visited[i]:
            s.append(i+1)
            visited[i] = True
            invite.add(i+1)
            func(k+1)
            visited[i] = False

func(0)
print(len(invite))
```