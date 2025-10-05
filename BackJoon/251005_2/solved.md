# 미로 탐색
##### 난이도: ***S1***
##### Link: https://www.acmicpc.net/problem/2178
##### Tag:  그래프 이론, 그래프 탐색, 너비 우선 탐색, 격자 그래프
##### 풀이 일자: 2025년 10월 5일
***
## 문제 탐색하기
BFS(Breadth Frist Search)방법을 통해 너비 우선 탐색 방법으로 미로의 최단 탈출거리를 계산하자!

### 해결요소
1. 미로 입력 받기 => input 영역 설정
2. 미로의 시작점과 끝점 설정
3. 시작점을 큐와, visited에 넣기
4. queue가 존재하면 탈출구를 찾을때까지 반복
5. queue에서 가장 왼쪽 요소를 1개 빼고, 이를 유효범위 안에서 이동
6. 모든 탐색을 완료하면 도착지까지 최저거리를 계산(최소 횟수만에 도달하니까)
***
## 코드 설계하기
```
----------------------------------------------------
# 가로 세로 입력받기
n, m = map(int, key_in().split())

# 맵을 저장할 graph 리스트
graph = []

# 반복문을 통하여 저장하기
for i in range(n):
    row_list = []
    row = key_in()
    for i in row:
        row_list.append(int(i))
    graph.append(row_list)
----------------------------------------------------
# 변수 설정
from collections import deque

start = (0, 0)
next_loc = deque([start])
visited = set([start])

# 처음 출발지로부터 이동할 거리 이중 리스트
dist = [[0]*m for _ in range(n)]
dist[0][0] = 1

# x, y 이동 방식
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
----------------------------------------------------
# 다음 장소로 가는 곳이 있을 때 까지 반복
while next_loc:
    x, y = next_loc.popleft()

    # 만약 뽑은 좌표가 목적지랑 같다면 탈출
    if (x, y) == (n-1, m-1):
        print(dist[x][y])
        break

    # 상하좌우 탐색
    for d in range(4):
        nx = x + dx[d]
        ny = y + dy[d]

        if 0<=nx<n and 0<=ny<m and graph[nx][ny] == 1 and (nx, ny) not in visited:
            next_loc.append((nx, ny))
            visited.add((nx, ny))
            dist[nx][ny] = dist[x][y] + 1
----------------------------------------------------
```
### ★★★시간 복잡도★★★
##### O(NxM)
모든 칸이 큐에 들어감으로 그래프의 넓이인 NxM이 시간 복잡도가 됨

***
## 시도 회차 수정사항
- 가로 세로를 x랑 y로 설정했는데, 기존 수학 그래프 그리는 것과 많이 혼동이 되어 IndexOutOfRange 에러가 종종 발생
- 거리를 세는 로직을 다시 계산 => 점진적으로 증가하는 방식이 아닌, 같은 크기의 그래프에서 한칸씩 이동할 때마다, 그 거리를 기록!!
- 암튼 많이 어려우니까 자주 연습하기!!!

***
## 정답 코드
```
# 표준 입력
import sys

key_in = lambda: sys.stdin.readline().rstrip()

# 가로 세로 입력받기
n, m = map(int, key_in().split())

# 맵을 저장할 graph 리스트
graph = []

# 반복문을 통하여 저장하기
for i in range(n):
    row_list = []
    row = key_in()
    for i in row:
        row_list.append(int(i))
    graph.append(row_list)


# 변수 설정
from collections import deque

start = (0, 0)
next_loc = deque([start])
visited = set([start])

# 처음 출발지로부터 이동할 거리 이중 리스트
dist = [[0]*m for _ in range(n)]
dist[0][0] = 1

# x, y 이동 방식
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]


# 다음 장소로 가는 곳이 있을 때 까지 반복
while next_loc:
    x, y = next_loc.popleft()

    # 만약 뽑은 좌표가 목적지랑 같다면 탈출
    if (x, y) == (n-1, m-1):
        print(dist[x][y])
        break

    # 상하좌우 탐색
    for d in range(4):
        nx = x + dx[d]
        ny = y + dy[d]

        if 0<=nx<n and 0<=ny<m and graph[nx][ny] == 1 and (nx, ny) not in visited:
            next_loc.append((nx, ny))
            visited.add((nx, ny))
            dist[nx][ny] = dist[x][y] + 1


```