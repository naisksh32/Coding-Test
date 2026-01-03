from collections import deque

# 테스트 케이스 수 입력
T = int(input())

# 8방향
dy = [-1, -1, 0, 1, 1, 1, 0, -1]
dx = [0, 1, 1, 1, 0, -1, -1, -1]

def func():
    N = int(input())
    matrix = []
    for _ in range(N):
        matrix.append(list(input().strip()))

    # 특정 좌표 (y, x) 주변의 지뢰 개수를 반환
    def count_mines(y, x):
        mine_cnt = 0
        for d in range(8):
            ny, nx = y + dy[d], x + dx[d]
            if 0 <= ny < N and 0 <= nx < N:
                if matrix[ny][nx] == '*':
                    mine_cnt += 1
        return mine_cnt

    # 0인 지점을 클릭했을 때 주변을 연쇄적으로 여는 BFS
    def bfs(start_y, start_x):
        q = deque()
        q.append((start_y, start_x))
        # 시작 지점은 이미 0임이 확인되었으므로 방문 처리(숫자로 변경)
        matrix[start_y][start_x] = 0
        
        while q:
            y, x = q.popleft()
            
            for d in range(8):
                ny, nx = y + dy[d], x + dx[d]
                
                # 범위 내에 있고, 아직 방문하지 않은 빈 칸('.')이라면
                if 0 <= ny < N and 0 <= nx < N and matrix[ny][nx] == '.':
                    # 주변 지뢰 개수 계산
                    mines = count_mines(ny, nx)
                    
                    # 방문 처리 (지도에 숫자를 기록)
                    matrix[ny][nx] = mines
                    
                    # 만약 주변 지뢰가 0개라면, 큐에 넣어서 계속 확장
                    # (0이 아니면 숫자만 기록하고 큐에는 넣지 않음 -> 확장의 경계)
                    if mines == 0:
                        q.append((ny, nx))

    cnt = 0

    for i in range(N):
        for j in range(N):
            # 빈 칸이면서, 주변 지뢰가 0개인 곳을 발견하면
            if matrix[i][j] == '.' and count_mines(i, j) == 0:
                cnt += 1      # 클릭 횟수 증가
                bfs(i, j)     # BFS로 연결된 0과 그 테두리 숫자들을 모두 엽니다.

    for i in range(N):
        for j in range(N):
            # BFS에 휩쓸리지 않고 여전히 '.'으로 남아있는 칸들은
            # 주변에 지뢰가 있는(숫자가 1 이상인) 독립적인 칸들입니다.
            if matrix[i][j] == '.':
                cnt += 1
                matrix[i][j] = count_mines(i, j) # 방문 처리 (사실 카운트만 세면 되지만 명시적으로 변경)

    return cnt

# 실행
for t in range(1, T + 1):
    result = func()
    print(f'#{t} {result}')