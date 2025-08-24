# 표준 입력 형성
import sys
input = lambda: sys.stdin.readline().rstrip()

# 명령의 수 입력
T = int(input())

# 주어진 명령을 수행할 빈 배열 생성
stack = []

# 주어진 명령동안 반복
for _ in range(T):
    # 명령을 입력 받음
    cmd = list(map(int, input().split()))
    
    # 명령어의 분기마다 다음 행동을 실행    
    match cmd[0]:
        
        # push: num을 스택에 추가
        case 1:
            stack.append(cmd[1])
            
        # pop: 스택의 가장 위 요소를 제거, 그 수를 출력 // 만약 없는 경우에는 -1 출력
        case 2:
            print(stack.pop() if stack else -1)
            
        # size: 현재 스택의 길이를 출력
        case 3:
            print(len(stack))
        
        # empty: 스택이 비어있으면 1, 아니면 0을 출력
        case 4:
            print(0 if stack else 1)
        
        # top: 스택의 가장 위에 있는 정수를 출력 // 만약 없는 경우에는 -1 출력
        case 5:
            print(stack[-1] if stack else -1)