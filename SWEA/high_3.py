from collections import deque

T = int(input())

def func():
    N = int(input())

    matrix = []
    for _ in range(N):
        row = list(map(int, input().split()))
        matrix.append(row)

    visited = [[-1] * N for _ in range(N)]

    start = tuple(map(int, input().split()))
    end = tuple(map(int, input().split()))

    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]

    # BFS 준비
    q = deque()
    q.append((start[0], start[1], 0))  # y, x, time
    visited[start[0]][start[1]] = 0

    # BFS 탐색
    while q:
        y, x, time = q.popleft()

        # 방문한 적이 있고, 기록된 시간보다 지금의 시간이 더 느리면 pass
        if visited[y][x] != -1 and visited[y][x] < time:
            continue

        # 4방향 탐색
        for d in range(4):
            ny = y + dy[d]
            nx = x + dx[d]

            # 범위 내 이면서 벽이 아닌 칸에 도달한 경우
            if 0 <= ny < N and 0 <= nx < N and matrix[ny][nx] != 1:
                next_time = time + 1

                # 소용돌이를 만난 경우
                if matrix[ny][nx] == 2:
                    wait = 0
                    # 3초의 배수가 아닌 경우
                    if next_time % 3 != 0:
                        # 소용돌이가 꺼지는 대기 시간을 추가
                        wait = 3 - (next_time % 3)
                    
                    final_time = next_time + wait

                    # 만약 소용돌이를 통해서 더 빨리 도달할 수 있으면 갱신
                    if visited[ny][nx] == -1 or visited[ny][nx] > final_time:
                        visited[ny][nx] = final_time
                        q.append((ny, nx, final_time))

                # 일반 길인 경우
                else:
                    if visited[ny][nx] == -1 or visited[ny][nx] > next_time:
                        visited[ny][nx] = next_time
                        q.append((ny, nx, next_time))

    return visited[end[0]][end[1]]

for t in range(T):
    answer = func()
    print(f'#{t+1} {answer}')