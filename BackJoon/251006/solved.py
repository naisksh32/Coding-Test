# 표준 입력
import sys

key_in = lambda: sys.stdin.readline().rstrip()


# BFS 함수 설정
def bfs(graph):

    # 변수 설정
    from collections import deque

    next_loc = deque()      # 다음 탐색범위를 지정할 queue
    visited = set()         # 이미 방문한 좌표를 저장할 set
    areas = []              # 배추밭 넓이를 저장할 list

    # 상하좌우 탐색을 위한 리스트
    dx = [1, -1, 0, 0]
    dy = [0 ,0, 1, -1]

    # 이중 반복문으로 탐색 (헹 -> 열 세부탐색)
    for i in range(N):
        for j in range(M):

            area = 0    # 처음 탐색시 넓이는 0

            # 시작점이 설정되지 않았으면 설정
            if not (next_loc) and graph[i][j] == 1 and (i, j) not in visited:

                # 다음 탐색을 위한 힌트와 방문장소 추가, 그리고 넓이 1 설정
                next_loc.append((i, j))
                visited.add((i, j))
                area = 1
            

            # 다음 장소를 탐색할 힌트가 남아있으면 탐색이 끝날 때 까지 반복
            while next_loc:

                # 현재 x, y좌표를 pop
                x, y = next_loc.pop()

                # 상하좌우 탐색
                for d in range(4):
                    nx = x + dx[d]
                    ny = y + dy[d]

                    # 이동한 좌표가 유효범위(1)이며, 아직 방문하지 않은 칸이면
                    if 0<=nx<N and 0<=ny<M and graph[nx][ny] == 1 and (nx, ny) not in visited:
                        
                        # 다음 탐색을 위한 힌트로 추가 및 방문장소 추가
                        next_loc.append((nx, ny))
                        visited.add((nx, ny))
                        area += 1   # 넓이도 1 추가
            
            # 만약 넓이가 유효(0 보다 크면)하면 추가
            if area > 0:
                areas.append(area)

    # 밭의 갯수를 출력
    print(len(areas))


# 몇번 반복할지 설정
T = int(key_in())

# 테스트 케이스 반목만큼 진행
for _ in range(T):

    # 가로, 세로, 배추 갯수를 입력받기
    M, N, K = map(int, key_in().split())

    # 가로, 세로 크기만큼 빈 배추밭 생성
    graph = [[0]*M for _ in range(N)]

    # 배추가 있는 좌표를 입력받아 배추 설정
    for _ in range(K):
        j, i = map(int, key_in().split())
        graph[i][j] = 1

    # 형성된 배추밭에 따라 bfs 진행
    bfs(graph)

