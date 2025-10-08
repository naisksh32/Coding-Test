# 표준 입력
import sys

key_in = lambda: sys.stdin.readline().rstrip()

T = int(key_in())		# 테스트 케이스

for _ in range(T):
    
	I = int(key_in())		# 체스판 한 변의 길이 (크기 IxI)

	move_cnt_graph = [[0]*I for _ in range(I)]		# 체스판 위 이동 횟수를 저장할 그래프

	start_point = tuple(map(int, key_in().split()))			# 시작 지점
	end_point = tuple(map(int, key_in().split()))			 # 도착 지점

	# 나이트가 이동하는 8가지 방향
	move_x = [2, 1, -1, -2, -2, -1, 1, 2]
	move_y = [1, 2, 2, 1, -1, -2, -2, -1]


	# BFS 탐색을 위한 변수 설정
	from collections import deque

	next_loc = deque([start_point])		# 다음 지점의 힌트가 되는 queue
	visited = set([start_point])			 # 이미 방문한 지역을 저장하는 set

	# next_loc가 살아있다는 전체 하에
	while next_loc:
		
		# 현재 목적지를 추출
		x, y = next_loc.popleft()
		
		# 만약 좌표가 도착지랑 일치하면 반복문 종료
		if (x, y) == end_point:
			print(move_cnt_graph[x][y])
			break
		
		# 8가지 방향으로 탐색
		for d in range(len(move_x)):
			dx = x + move_x[d]
			dy = y + move_y[d]
			
			# 만약 움직인 장소가 유효범위 내이고, 방문하지 않은 장소라면
			if 0<=dx<I and 0<=dy<I and (dx, dy) not in visited:
				# 이동
				next_loc.append((dx, dy))
				visited.add((dx, dy))
				# 기존 좌표에서 1회 이동 추가
				move_cnt_graph[dx][dy] = move_cnt_graph[x][y] + 1
				