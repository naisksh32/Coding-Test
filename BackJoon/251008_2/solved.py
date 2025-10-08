# 표준 입력
import sys

key_in = lambda: sys.stdin.readline().rstrip()

# 주어진 입력값 받기
M, N, H = map(int, key_in().split())
graph = [[list(map(int, input().split())) for _ in range(N)] for _ in range(H)]

# 좌우, 전후, 상하 이동방향 설정
dx, dy, dz = [1, -1, 0, 0, 0, 0], [0, 0, 1, -1, 0, 0], [0, 0, 0, 0, 1, -1]

# 안익은 토마토 갯수 설정
not_tomato = 0

# 초기 변수 설정
from collections import deque

next_loc = deque()		# 다음 좌표로 이동할 힌트 큐

# 3중 반복문을 통하여 시작점 설정
for k in range(H):
	for j in range(N):
		for i in range(M):
			
			# 시작점 위치 설정
			if graph[k][j][i] == 1:
				next_loc.append((i, j ,k))

			# 덜익은 토마토 갯수 세기
			elif graph[k][j][i] == 0:
				not_tomato += 1

# BFS로 익은 토마토를 계산하고, 최종 결과 도출하기
def BFS(not_tomato):

  	# 시작점을 기준으로 BFS 탐색 시작
	while next_loc:
		x, y, z = next_loc.popleft()
		
		# 좌우, 전후, 상하 이동방향으로 탐색
		for d in range(6):
			nx, ny, nz = x + dx[d], y + dy[d], z + dz[d]

			# 만약 이동한 방향이 유효범위 내이고, 이동 좌표가 0 이면
			if 0<=nx<M and 0<=ny<N and 0<=nz<H and graph[nz][ny][nx] == 0:
				graph[nz][ny][nx] = graph[z][y][x] + 1	# 최소 이동법을 위한 계산
				next_loc.append((nx, ny, nz))
				not_tomato -= 1		# 덜익은 토마토 갯수 감소

	# 모든 탐색을 마치고 덜익은 토마토가 0개면 날짜를 return
	if not_tomato == 0:
		return max(max(max(row) for row in plane) for plane in graph) - 1
	# 만약 덜익은 토마토가 존재하면 -1 return
	else:
		return -1

print(BFS(not_tomato))