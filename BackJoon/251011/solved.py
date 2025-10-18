# 표준 입력
import sys

key_in = lambda: sys.stdin.readline().rstrip()

N, M, V = map(int, key_in().split())

near_list = [[] for _ in range(N)]

for _ in range(M):
    s, e = map(int, key_in().split())
    near_list[s-1].append(e)
    near_list[e-1].append(s)

for i in range(N):
    try:
        near_list[i].sort()
    except:
        continue
    

# BFS 너비 우선 탐색
def BFS():
    from collections import deque
    
    # BFS 탐색을 위한 queue 자료형
    q = deque([V])
    # 방문점을 남기는 요소
    visited = set([V])
    
    # 큐에 탐색할 장소가 남아있으면 반복
    while q:
        # 제일 앞쪽 요소를 추출
        node = q.popleft()
        # 해당 노드 프린트
        print(node, end=' ')

        
        # 해당 노드가 갈 수 있는 방향을 넓게 탐색
        for i in range(len(near_list[node-1])):
            # 만약 탐색한 노드가 아직 방문하지 않았더라면
            if near_list[node-1][i] not in visited:
                q.append(near_list[node-1][i])      # 다음 탐색 장소에 추가
                visited.add(near_list[node-1][i])   # 방문한 장소에도 추가

# DFS 깊이 우선 탐색
def DFS():
    stack = [V]
    visited= [False for _ in range(N)]
    visited[V-1] = True
    
    def func():
        node = stack.pop()
        print(node, end=' ')
            
        if not near_list[node-1]:
            return
        
        for i in range(len(near_list[node-1])):
            
            if visited[near_list[node-1][i]-1]:
                continue
            
            stack.append(near_list[node-1][i])
            visited[near_list[node-1][i]-1] = True
            func()

    func()
        
        
DFS()
print()
BFS()
