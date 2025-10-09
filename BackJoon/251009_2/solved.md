# 말이 되고픈 원승이
##### 난이도: ***G3***
##### Link: https://www.acmicpc.net/problem/1600
##### Tag:  그래프 이론, 그래프 탐색, 너비 우선 탐색
##### 풀이 일자: 2025년 10월 9일
***
## 문제 탐색하기
BFS(Breadth Frist Search)방법을 통해 격자 미로의 탈출구를 찾자!
BFS 방법 특성상 가장 먼저 나오는 탈출 방법이 최단 경로임을 이용하자!

### 해결요소
1. 지난번 나이트 이동 문제와, 상하좌우 이동 문제가 섞여있다.
2. 모든 경우를 queue에 저장하여 하나씩 탐색한다.

***
## 코드 설계하기
```
----------------------------------------------------
# 입력값
K = int(key_in())
W, H = map(int, key_in().split())

graph = []
for _ in range(H):
    graph.append(list(map(int, key_in().split())))
----------------------------------------------------
# 이동거리를 표시하기 위한 거리그래프
dist_graph = [[[0]*W for _ in range(H)] for _ in range(K+1)]

# 말의 이동방식
horse_x = [2, 1, 2, 1, -2, -1, -2, -1]
horse_y = [1, 2, -1, -2, 1, 2, -1, -2]
# 원숭이의 이동방식
monkey_x = [1, -1, 0, 0]
monkey_y = [0, 0, 1, -1]
----------------------------------------------------
# BFS 탐색을 위한 변수 설정
from collections import deque

start_p = (0, 0, K)		# 시작점 + 말 움직임 횟수
end_p = (W-1, H-1)		# 도착점

next_loc = deque([start_p])	# 다음 이동을 위한 큐
visited = set([start_p])	# 방문한 장소 기록 세트
----------------------------------------------------
# BFS 탐색 시작
while next_loc:
	# 현재 정보를 추출
	x, y, h_cnt = next_loc.popleft()

	# 만약 도착 지점이랑 같다면
	if (x, y) == end_p:
		return dist_graph[h_cnt][y][x]
----------------------------------------------------
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
----------------------------------------------------
```
### ★★★시간 복잡도★★★
##### O(WxHxK)
모든칸(WxH)에 대해서 최대 몇 번(K) 말의 움직임을 구현할 수 있는가가 시간복잡도가 된다.
최악의 경우 200x200x30의 시간복잡도를 가지게 된다.

***
## 시도 회차 수정사항
- 말의 이동 방식과 원숭이의 이동방식을 구현
- 이 두개를 동시에 큐에 저장
- 최종 결과를 낼 때, 바로 결과가 나오는 것이 최단 경로임을 고려하지 못함 => 추출된 정보를 바탕으로 최단 경로를 확정

***
## 정답 코드
```
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
```