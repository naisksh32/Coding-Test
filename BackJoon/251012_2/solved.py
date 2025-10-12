# 표준 입력
import sys

key_in = lambda: sys.stdin.readline().rstrip()

n = int(key_in())
m = int(key_in())
graph = [[0]*n for _ in range(n)]
for _ in range(m):
    ai, bi = map(int, key_in().split())
    graph[ai-1][bi-1] = 1
    graph[bi-1][ai-1] = 1


# DFS 변수 설정
s = []
visited = [False] * n
invite = set()

# DFS 초깃값 설정 (node 1 방문)
s.append(1)
visited[0] = True

def func(k):
    
    # depth를 2번 탔다 -> 함수 종료
    if k == 2:
        return
    
    node = s.pop()
    for i in range(len(graph[node-1])):
        if graph[node-1][i] == 1 and not visited[i]:
            s.append(i+1)
            visited[i] = True
            invite.add(i+1)
            func(k+1)
            visited[i] = False

func(0)
print(len(invite))