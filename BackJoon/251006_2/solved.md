# 적록색약 
##### 난이도: ***G5***
##### Link: https://www.acmicpc.net/problem/10026
##### Tag:  그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색, 격자 그래프
##### 풀이 일자: 2025년 10월 6일
***
## 문제 탐색하기
BFS(Breadth Frist Search)방법을 이용하여 탐색 영역을 확정짓고, 각 영역별로 탐색한 영역의 넓이, 그리고 갯수를 파악하자

### 해결요소
1. 맵 입력 받기 -> 반복문으로 graph 입력 받기
2. 정상인의 경우, R을 탐색하는 경우, G를 탐색하는 경우, B를 탐색하는 경우를 세분화 하여 이중 반복문으로 탐색  
(변수 초기화)
3. 적록색맹의 경우, RG를 혼합하여 탐색하는 경우, B를 탐색하는 경우를 세분화 하여 이중 반복문으로 탐색
4. 각 경우별로 탐색한 영역의 갯수를 return
***
## 코드 설계하기
```
----------------------------------------------------
# 주어진 영역 입력받기
N = int(key_in())
graph = []

for _ in range(N):
    row = key_in()
    line = []
    for item in row:
        line.append(item)
    graph.append(line)
----------------------------------------------------
# 변수 설정
from collections import deque

next_loc = deque()
visited = set()

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
----------------------------------------------------
normal = []     # 일반인이 바라보는 영역

# 정상인이 바라보는 영역 (R, G, B) 모두 구분
for i in range(N):
    for j in range(N):

        red_area = 0
        green_area = 0
        red_green_area = 0
        blue_area = 0
----------------------------------------------------
# 빨간색 영역 탐색
if graph[i][j] == 'R':

    if not(next_loc) and (i, j) not in visited:
        next_loc.append((i, j))
        visited.add((i, j))
        red_area = 1


    while next_loc:
        x, y = next_loc.popleft()

        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]

            if 0<=nx<N and 0<=ny<N and graph[nx][ny] == 'R' and (nx, ny) not in visited:
                next_loc.append((nx, ny))
                visited.add((nx, ny))
                red_area += 1
----------------------------------------------------
# 초록색 영역 탐색
elif graph[i][j] == 'G':

    if not(next_loc) and (i, j) not in visited:
        next_loc.append((i, j))
        visited.add((i, j))
        green_area = 1


    while next_loc:
        x, y = next_loc.popleft()

        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]

            if 0<=nx<N and 0<=ny<N and graph[nx][ny] == 'G' and (nx, ny) not in visited:
                next_loc.append((nx, ny))
                visited.add((nx, ny))
                green_area += 1
----------------------------------------------------
# 파란색 영역 탐색
elif graph[i][j] == 'B':

    if not(next_loc) and (i, j) not in visited:
        next_loc.append((i, j))
        visited.add((i, j))
        blue_area = 1


    while next_loc:
        x, y = next_loc.popleft()

        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]

            if 0<=nx<N and 0<=ny<N and graph[nx][ny] == 'B' and (nx, ny) not in visited:
                next_loc.append((nx, ny))
                visited.add((nx, ny))
                blue_area += 1
----------------------------------------------------
# 영역 추가
if red_area > 0:
    normal.append({'Red':red_area})
elif green_area > 0:
    normal.append({'Green':green_area})
elif blue_area > 0:
    normal.append({'Blue':blue_area})
----------------------------------------------------
not_green = []  # 적록색약이 바라보는 영역

# 새롭게 초기화
next_loc = deque()
visited = set()

# 적록색맹이 바라보는 영역 ((R, G), B) 모두 구분
for i in range(N):
    for j in range(N):

        red_green_area = 0
        blue_area = 0
----------------------------------------------------
# 빨간색+초록색 영역 탐색
if graph[i][j] == 'R' or graph[i][j] == 'G':

    # 시작점이 설정되지 않았으면 시작점 설정
    if not(next_loc) and (i, j) not in visited:
        next_loc.append((i, j))
        visited.add((i, j))
        red_green_area = 1

    # 다음 방향이 정해지면 탐색 시작
    while next_loc:
        x, y = next_loc.popleft()

        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]

            if 0<=nx<N and 0<=ny<N and (graph[nx][ny] == 'R' or graph[nx][ny] == 'G') and (nx, ny) not in visited:
                next_loc.append((nx, ny))
                visited.add((nx, ny))
                red_green_area += 1
----------------------------------------------------
# 파란색 영역 탐색
elif graph[i][j] == 'B':

    if not(next_loc) and (i, j) not in visited:
        next_loc.append((i, j))
        visited.add((i, j))
        blue_area = 1


    while next_loc:
        x, y = next_loc.popleft()

        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]

            if 0<=nx<N and 0<=ny<N and graph[nx][ny] == 'B' and (nx, ny) not in visited:
                next_loc.append((nx, ny))
                visited.add((nx, ny))
                blue_area += 1
----------------------------------------------------
# 영역 추가
if red_green_area > 0:
    not_green.append({'Red+Green':red_green_area})
elif blue_area > 0:
    not_green.append({'Blue':blue_area})
----------------------------------------------------
# 각 조건별로 출력
print(len(normal), len(not_green))
----------------------------------------------------
```
### ★★★시간 복잡도★★★
##### O(NxN)
모든 칸이 큐에 들어감으로 그래프의 넓이인 NxN이 시간 복잡도가 됨  
N이 최대 100까지 될 수 있으므로, O(10000)이 최대 시간 복잡도

***
## 시도 회차 수정사항
- 기존에는 0과 1로 구분지어 1개의 영역만 판단했다면, 해당 문제는 R,G,B 각각의 영역을 구별해야 한다.
- 그래서 조건들이 엄청 세분화 되었고, 코드도 반복되는 요소가 많아져 길어졌다.  
(다행히 시간복잡도가 낮아 하드코딩 영역에서 해결하였다.)
- 해당 반복되는 요소들을 줄일 수 있는 방법을 고안해보기
- 암튼 많이 어려우니까 자주 연습하기!!!

***
## 정답 코드
```
# 표준 입력
import sys

key_in = lambda: sys.stdin.readline().rstrip()

N = int(key_in())
graph = []

for _ in range(N):
    row = key_in()
    line = []
    for item in row:
        line.append(item)
    graph.append(line)


# 적록색약X -> R, G, B 영역 각각 구분
# 적록색약O -> (R, G), B 2개의 영역 구분

# 변수 설정
from collections import deque

next_loc = deque()
visited = set()

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

normal = []     # 일반인이 바라보는 영역

# 정상인이 바라보는 영역 (R, G, B) 모두 구분
for i in range(N):
    for j in range(N):

        red_area = 0
        green_area = 0
        red_green_area = 0
        blue_area = 0

        # 빨간색 영역 탐색
        if graph[i][j] == 'R':

            if not(next_loc) and (i, j) not in visited:
                next_loc.append((i, j))
                visited.add((i, j))
                red_area = 1

        
            while next_loc:
                x, y = next_loc.popleft()

                for d in range(4):
                    nx = x + dx[d]
                    ny = y + dy[d]

                    if 0<=nx<N and 0<=ny<N and graph[nx][ny] == 'R' and (nx, ny) not in visited:
                        next_loc.append((nx, ny))
                        visited.add((nx, ny))
                        red_area += 1

        # 초록색 영역 탐색
        elif graph[i][j] == 'G':

            if not(next_loc) and (i, j) not in visited:
                next_loc.append((i, j))
                visited.add((i, j))
                green_area = 1

        
            while next_loc:
                x, y = next_loc.popleft()

                for d in range(4):
                    nx = x + dx[d]
                    ny = y + dy[d]

                    if 0<=nx<N and 0<=ny<N and graph[nx][ny] == 'G' and (nx, ny) not in visited:
                        next_loc.append((nx, ny))
                        visited.add((nx, ny))
                        green_area += 1

        # 파란색 영역 탐색
        elif graph[i][j] == 'B':

            if not(next_loc) and (i, j) not in visited:
                next_loc.append((i, j))
                visited.add((i, j))
                blue_area = 1

        
            while next_loc:
                x, y = next_loc.popleft()

                for d in range(4):
                    nx = x + dx[d]
                    ny = y + dy[d]

                    if 0<=nx<N and 0<=ny<N and graph[nx][ny] == 'B' and (nx, ny) not in visited:
                        next_loc.append((nx, ny))
                        visited.add((nx, ny))
                        blue_area += 1

        if red_area > 0:
            normal.append({'Red':red_area})
        elif green_area > 0:
            normal.append({'Green':green_area})
        elif blue_area > 0:
            normal.append({'Blue':blue_area})



not_green = []  # 적록색약이 바라보는 영역

# 새롭게 초기화
next_loc = deque()
visited = set()

# 적록색맹이 바라보는 영역 ((R, G), B) 모두 구분
for i in range(N):
    for j in range(N):

        red_green_area = 0
        blue_area = 0

        # 빨간색+초록색 영역 탐색
        if graph[i][j] == 'R' or graph[i][j] == 'G':

            # 시작점이 설정되지 않았으면 시작점 설정
            if not(next_loc) and (i, j) not in visited:
                next_loc.append((i, j))
                visited.add((i, j))
                red_green_area = 1

            # 다음 방향이 정해지면 탐색 시작
            while next_loc:
                x, y = next_loc.popleft()

                for d in range(4):
                    nx = x + dx[d]
                    ny = y + dy[d]

                    if 0<=nx<N and 0<=ny<N and (graph[nx][ny] == 'R' or graph[nx][ny] == 'G') and (nx, ny) not in visited:
                        next_loc.append((nx, ny))
                        visited.add((nx, ny))
                        red_green_area += 1

        # 파란색 영역 탐색
        elif graph[i][j] == 'B':

            if not(next_loc) and (i, j) not in visited:
                next_loc.append((i, j))
                visited.add((i, j))
                blue_area = 1

        
            while next_loc:
                x, y = next_loc.popleft()

                for d in range(4):
                    nx = x + dx[d]
                    ny = y + dy[d]

                    if 0<=nx<N and 0<=ny<N and graph[nx][ny] == 'B' and (nx, ny) not in visited:
                        next_loc.append((nx, ny))
                        visited.add((nx, ny))
                        blue_area += 1

        if red_green_area > 0:
            not_green.append({'Red+Green':red_green_area})
        elif blue_area > 0:
            not_green.append({'Blue':blue_area})


print(len(normal), len(not_green))
```