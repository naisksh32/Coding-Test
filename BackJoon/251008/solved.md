# 나이트의 이동
##### 난이도: ***S1***
##### Link: https://www.acmicpc.net/problem/7562
##### Tag:  그래프 이론, 그래프 탐색, 너비 우선 탐색, 최단 경로, 격자 그래프
##### 풀이 일자: 2025년 10월 8일
***
## 문제 탐색하기
BFS(Breadth Frist Search)방법을 통해 나이트의 이동방향을 정의하고, 목표지점까지 최소 이동 거리를 구해라

### 해결요소
1. 나이트의 8가지 이동방향 결정 => dx, dy 리스트 형태로 각 좌표별 어떻게 이동하는지 기록
2. 유효범위내 이동 방향 탐색 => 조건문을 통하여 계산
3. 최소 이동 거리 계산 => 0으로 시작하는 체스판 맵을 만들어서 이동시 마다 점수를 부여하는 방법 채택

***
## 코드 설계하기
```
----------------------------------------------------
move_cnt_graph = [[0]*I for _ in range(I)]		# 체스판 위 이동 횟수를 저장할 그래프
'''
[[0, 0 ,0 ,0, 0],
[0, 0 ,0 ,0, 0],
[0, 0 ,0 ,0, 0],
[0, 0 ,0 ,0, 0],
[0, 0 ,0 ,0, 0],] I = 5인 0으로 구성된 그래프를 만들어서 도착 좌표마다 몇번 이동했는지 기록
''' 
----------------------------------------------------
# 나이트가 이동하는 8가지 방향, 그림 참조
move_x = [2, 1, -1, -2, -2, -1, 1, 2]
move_y = [1, 2, 2, 1, -1, -2, -2, -1]
----------------------------------------------------
# BFS 탐색을 위한 변수 설정
from collections import deque

next_loc = deque([start_point])		# 다음 지점의 힌트가 되는 queue
visited = set([start_point])			 # 이미 방문한 지역을 저장하는 set
----------------------------------------------------
# next_loc가 살아있다는 전체 하에
while next_loc:
	
	# 현재 목적지를 추출
	x, y = next_loc.popleft()
----------------------------------------------------
# 만약 좌표가 도착지랑 일치하면 반복문 종료
if (x, y) == end_point:
	print(move_cnt_graph[x][y])
	break
----------------------------------------------------
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
----------------------------------------------------
```
### ★★★시간 복잡도★★★
##### O(IxI)
최악의 경우 모든 칸을 탐색해야 함으로 I^2이 최대 시간복잡도가 됨(모든 칸이 반복문을 진행)
문제에서 I가 최대 300을 가짐으로 최대 시간 복잡도는 90,000
***
## 시도 회차 수정사항
- 기존 상하좌우를 탐색하는 BFS 문제랑은 다르게, 8가지 방향을 탐색하는 문제
- 최단 이동거리를 구해야 함으로, 기존의 pop의 갯수만 세는 방식 말고, map에서 이동거리를 누적해서 계산하는 방식 채택

***
## 정답 코드
```
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
				
```