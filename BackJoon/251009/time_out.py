# 표준 입력
import sys

key_in = lambda: sys.stdin.readline().rstrip()

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
start_p = (0, 0)
end_p = (N-1, M-1)

# 상하좌우 탐색 배열
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

# BFS 탐색을 위한 변수 설정
from collections import deque

# 어떤 벽을 부술지 벽의 좌표를 저장
break_wall = set()

# 벽의 갯수
wall = 0	
for j in range(N):
    for i in range(M):
        if graph[j][i] == 1:
            wall += 1


def BFS():
	
	# 어떤 벽을 부셔야 할지 모름으로 벽의 갯수만큼 반복 진행
	for _ in range(wall):
		
		# 매 시도마다 이동 횟수와 방문점은 초기화
		next_loc = deque([start_p])
		visited = set([start_p])
		
		# 벽을 부쉈는지 여부와 벽 부수기 횟수도 초기화
		is_break = False
		break_cnt = 1
		
		# BFS 탐색 시작
		while next_loc:
		
			# 현재 좌표를 추출
			x, y = next_loc.popleft()
			
			# 엔드포인트에 도달했으면 반복 종료, 먼저 도착하면 최단경로 자동적으로 달성
			if (y, x) == end_p:
				return dist_graph[y][x]

			# 상하좌우 탐색
			for d in range(4):
				nx, ny = x+dx[d], y+dy[d]
				
				# 유효범위 내 이고, 아직 방문하지 않은 좌표이면
				if 0<=nx<M and 0<=ny<N and (nx, ny) not in visited:
				
    				# 이동할 수 있는 방향이면 정상적으로 BFS 탐색 진행
					if graph[ny][nx] == 0:
						next_loc.append((nx, ny))
						visited.add((nx, ny))
						dist_graph[ny][nx] = dist_graph[y][x] + 1
		
					# 아직 벽을 부술수 있는 횟수가 남아있으며, 가는 방향이 벽이며, 부수지 않은 벽일때
					if break_cnt > 0 and graph[ny][nx] == 1 and (nx, ny) not in break_wall:
						
						is_break = True				# 벽을 부쉈다.
						break_wall.add((nx, ny))	# 부순 벽의 좌표를 저장

						# 정상적으로 이동 진행
						next_loc.append((nx, ny))
						visited.add((nx, ny))
						dist_graph[ny][nx] = dist_graph[y][x] + 1

			# 네방향 탐색이 끝난 후 벽부수기 정산
			if is_break:
				break_cnt -= 1		# 벽부수기 횟수 1회 감소
				is_break = False	# 벽 안부셨다.
    
	return -1
 
print(BFS())