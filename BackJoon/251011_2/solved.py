# 표준 입력
import sys

key_in = lambda: sys.stdin.readline().rstrip()


N, M, V = list(map(int, key_in().split()))

graph = [[0]*4 for _ in range(N)]

for _ in range(M):
    x, y = map(int, key_in().split())
    graph[x-1][y-1] = 1

# print(graph)
# graph = [[0, 1, 1, 1], [0, 0, 0, 1], [0, 0, 0, 1], [0, 0, 0, 0]]

"""
인접 행렬로 표시
   1  2  3  4
1  0  1  1  1
2  0  0  0  1
3  0  0  0  1
4  0  0  0  0
"""
near_list = [[2, 3, 4], [4], [4], []]
"""
인접 리스트로 표시
1  2 3 4
2  4
3  4
4
"""


# BFS 실행
def BFS():
    from collections import deque

    q = deque([V])
    visited = set([V])

    while q:
        n = q.popleft()
        print(n, end=" ")

        for i in range(len(graph[n - 1])):
            next_node = i + 1

            if graph[n - 1][i] == 1 and next_node not in visited:
                q.append(next_node)
                visited.add(next_node)


def DFS_recure():
    visited = [False]*N

    def func(k):
        visited[k] = True
        print(k+1, end=' ')
        
        for i in range(len(graph[k])):

            if visited[i] or graph[k][i] == 0:
                continue

            func(i)
    
    func(0)
		

DFS_recure()
print()
BFS()
