# 토마토
##### 난이도: ***G5***
##### Link: https://www.acmicpc.net/problem/7569
##### Tag:  그래프 이론, 그래프 탐색, 너비 우선 탐색, 최단 경로, 격자 그래프
##### 풀이 일자: 2025년 10월 8일
***
## 문제 탐색하기
BFS(Breadth Frist Search)방법을 통하여 토마토 전이를 실행시키자

### 해결요소
1. 3차원 배열로 구성된 토마토의 이동방향 정하기
2. 날짜가 지날수록 기존 토마토에서 얼마만큼 지났는지 보이기
3. 최종적으로 덜익은 토마토가 없으면, 최대 날짜를 return
4. 덜익은 토마토가 존재하면 -1을 return

***
## 코드 설계하기
```
----------------------------------------------------
# 리스트 컴프리헨션을 적극 활용하여 주어진 입력값 받기
M, N, H = map(int, key_in().split())
graph = [[list(map(int, input().split())) for _ in range(N)] for _ in range(H)]
----------------------------------------------------
# 좌우, 전후, 상하 이동방향 설정
dx, dy, dz = [1, -1, 0, 0, 0, 0], [0, 0, 1, -1, 0, 0], [0, 0, 0, 0, 1, -1]
----------------------------------------------------
# 안익은 토마토 갯수 설정
not_tomato = 0
----------------------------------------------------
# 초기 변수 설정
from collections import deque

next_loc = deque()		# 다음 좌표로 이동할 힌트 큐
----------------------------------------------------
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
----------------------------------------------------
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
----------------------------------------------------
# 모든 탐색을 마치고 덜익은 토마토가 0개면 날짜를 return
if not_tomato == 0:
	return max(max(max(row) for row in plane) for plane in graph) - 1
# 만약 덜익은 토마토가 존재하면 -1 return
else:
	return -1
----------------------------------------------------
```
### ★★★시간 복잡도★★★
##### O(MxNxH)
최악의 경우 모든 칸을 탐색해야 함으로 MxNxH가 최대 시간 복잡도.  
각 변수는 최대 100을 가질 수 있으므로, 최대 1,000,000의 시간복잡도를 가짐
***
## 시도 회차 수정사항
- 3차원 배열로 구성됨으로 이동하는 방향 잘 설정하기
- 날짜의 최댓값을 결정함에 있어, 리스트 컴프리헨션으로 반복문을 통한 요소 검색을 하다보니, 시간복잡도가 점점 더 늘어나게 되었고, 결국 timeout이 발생하게 되었다.
- 이를 해결하기 위해 다른 변수(덜 익은 토마토)로 상황이 종료되었는지 판단하였다.
***
## 정답 코드
```
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
```