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