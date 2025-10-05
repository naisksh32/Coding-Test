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
