# 표준 입력
import sys

key_in = lambda: sys.stdin.readline().rstrip()

N = int(key_in())
R = int(key_in())
graph = [[0]*N for _ in range(N)]
for i in range(R):
    s, e = map(int, key_in().split())
    graph[s-1][e-1] = 1
    graph[e-1][s-1] = 1

# BFS 탐색 방식으로 구현
from collections import deque

q = deque()
visited = set()

q.append(1)
visited.add(1)

while q:
    node = q.popleft()
    
    for i in range(len(graph[node-1])):
        if graph[node-1][i] == 1 and (i+1) not in visited:
            q.append(i+1)
            visited.add(i+1)
            
            
print(len(visited)-1)