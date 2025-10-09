# 표준 입력
import sys

key_in = lambda: sys.stdin.readline().rstrip()

# 입력값
K = int(key_in())
W, H = map(int, key_in().split())

graph = []
for _ in range(H):
    graph.append(list(map(int, key_in().split())))


# 이동거리를 표시하기 위한 거리그래프
dist_graph = [[[0]*W for _ in range(H)] for _ in range(K+1)]

# 말의 이동방식
horse_x = [2, 1, 2, 1, -2, -1, -2, -1]
horse_y = [1, 2, -1, -2, 1, 2, -1, -2]
# 원숭이의 이동방식
monkey_x = [1, -1, 0, 0]
monkey_y = [0, 0, 1, -1]

# BFS 탐색을 위한 변수 설정
from collections import deque

start_p = (0, 0, K)		# 시작점 + 말 움직임 횟수
end_p = (W-1, H-1)		# 도착점

next_loc = deque([start_p])	# 다음 이동을 위한 큐
visited = set([start_p])	# 방문한 장소 기록 세트

def BFS():	
	while next_loc:
    	# 현재 정보를 추출
		x, y, h_cnt = next_loc.popleft()

		# 만약 도착 지점이랑 같다면
		if (x, y) == end_p:
			return dist_graph[h_cnt][y][x]

		# 말의 이동 움직임이 남아 있다면
		if h_cnt:
			for d in range(8):
				nx, ny, h = x+horse_x[d], y+horse_y[d], h_cnt-1
				if 0<=nx<W and 0<=ny<H and (nx, ny, h) not in visited and graph[ny][nx] == 0:
					next_loc.append((nx, ny, h))
					visited.add((nx, ny, h))
					dist_graph[h][ny][nx] = dist_graph[h_cnt][y][x] + 1
	
		# 일반 원숭이의 움직임
		for d in range(4):
			nx, ny, h = x+monkey_x[d], y+monkey_y[d], h_cnt
			if 0<=nx<W and 0<=ny<H and (nx, ny, h) not in visited and graph[ny][nx] == 0:
				next_loc.append((nx, ny, h))
				visited.add((nx, ny, h))
				dist_graph[h][ny][nx] = dist_graph[h_cnt][y][x] + 1
    
	return -1


print(BFS())