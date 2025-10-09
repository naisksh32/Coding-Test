# 표준 입력
import sys

key_in = lambda: sys.stdin.readline().rstrip()

# 주어진 입력
N, M = map(int, key_in().split())

graph = []
for _ in range(N):
    line = []
    for i in key_in():
        line.append(int(i))
    graph.append(line)


# 거리를 기록할 그래프
dist_graph = [[0]*M for _ in range(N)]
dist_graph[0][0] = 1	# 초기 거리 설정

# 스타트 포인트와 엔드 포인트 지정
start_p = [0, 0]
end_p = (N-1, M-1)

# 상하좌우 탐색 배열
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

# 최대 벽을 부술 수 있는 횟수
break_cnt = 1

# BFS 탐색을 위한 변수 설정
from collections import deque

start_p.append(break_cnt)

next_loc = deque([tuple(start_p)])	# 초기 시작점에 시작점 좌표랑 벽부수기 횟수를 같이 저장
visited = set([tuple(start_p)])	# 방문한 지점의 좌표를 저장


def BFS():

	# BFS 탐색 시작
	while next_loc:
	
		# 현재 좌표를 추출
		x, y, break_cnt = next_loc.popleft()
		
		# 엔드포인트에 도달했으면 반복 종료, 먼저 도착하면 최단경로 자동적으로 달성
		if (y, x) == end_p:
			return dist_graph[y][x]

		# 상하좌우 탐색
		for d in range(4):
			nx, ny = x+dx[d], y+dy[d]
			
			# 유효범위 내 이고, 아직 방문하지 않은 좌표이면
			if 0<=nx<M and 0<=ny<N and (nx, ny, break_cnt) not in visited:
			
				# 벽을 부수지 않고 이동할 수 있는 방향이면 정상적으로 BFS 탐색 진행
				if graph[ny][nx] == 0:
					next_loc.append((nx, ny, break_cnt))
					visited.add((nx, ny, break_cnt))
					dist_graph[ny][nx] = dist_graph[y][x] + 1
	
				# 아직 벽을 부술수 있는 횟수가 남아있으며, 가는 방향이 벽이며, 부수지 않은 벽일때
				elif break_cnt > 0 and graph[ny][nx] == 1 and (nx, ny):

					# 정상적으로 이동 진행
					next_loc.append((nx, ny, break_cnt-1))
					visited.add((nx, ny, break_cnt-1))
					dist_graph[ny][nx] = dist_graph[y][x] + 1

	return -1
 
print(BFS())