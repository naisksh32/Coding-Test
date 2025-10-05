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
    for num in map(int, key_in().split()):
        row_list.append(num)
    graph.append(row_list)


from collections import deque

queue = deque()     # 좌표를 담을 큐
visited = set()     # 방문 여부를 담을 set
pictures = []       # 그림을 저장할 리스트


# 이중 반복문으로 모든 구간을 탐색
for i in range(n):
    for j in range(m):
        
        # 회차 반복 시 처음 그림 크기는 0으로 초기화 (다른곳에서 중복적으로 추가되는 것을 방지)
        size = 0

        # 만약 처음 시작점이 비어있으면 queue에 추가
        if (graph[i][j] == 1) and (not queue) and ((i, j) not in visited):
            queue.append((i, j))    # 현재 좌표를 queue에 추가
            visited.add((i, j))     # 방문했다고 visited에 남김
            size = 1                # 1이 존재함으로, 그림크기는 1

        # 큐에 내용이 있다면, 그 지점을 기준으로 탐색 시작
        while queue:
            # 현재 queue에 있는 좌표를 뽑아 상하좌우 분석
            x, y = queue.pop()

            # 상하좌우 분석
            for dx, dy in [[x+1, y], [x-1, y], [x, y+1], [x, y-1]]:
                # 이동한 x랑 y가 유효범위 내에 있으며, 방문하지 않았던 장소라면 이동
                if 0<=dx<n and 0<=dy<m and graph[dx][dy] == 1 and (dx, dy) not in visited:
                    queue.append((dx, dy))  # 이동방향을 저장 (기존위치에서 움직인 방향)
                    visited.add((dx, dy))   # 방문했다고 visited에도 남김
                    size += 1               # 그림크기 1추가

        # 해당 회차를 마치며
        # 그림의 크기가 0보다 클때에만 저장
        if size > 0:
            pictures.append(size)

# 모든 이중 반복을 마치고
print(len(pictures))    # 그림의 갯수
if pictures:
    print(max(pictures))    # 가장 큰 그림의 넓이
else:
    print(0)    # 그림이 없는 경우