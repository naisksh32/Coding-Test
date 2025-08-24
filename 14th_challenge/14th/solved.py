# 표준 입력 형성
import sys
input = lambda: sys.stdin.readline().rstrip()

# 큐 자료형 생성
from collections import deque
queue = deque()

# 반복할 명령어 수
T = int(input())

for _ in range(T):
    cmd= input().split()
        
    match cmd[0]:   
        # 자료 추가
        case "push":
            queue.append(cmd[1])

		# 자료 제거
        case "pop":
            print(queue.popleft() if queue else -1)
        
        # 자료 크기
        case "size":
            print(len(queue))
        
        # 자료 유무
        case "empty":
            print(0 if queue else 1)
        
        # 제일 앞 자료
        case "front":
            print(queue[0] if queue else -1)
        
        # 제일 뒷 자료
        case "back":
            print(queue[-1] if queue else -1)    
