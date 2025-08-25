# 표준 입력 형성
import sys
input = lambda: sys.stdin.readline().rstrip()

# 덱 자료구조 생성
from collections import deque
deck = deque()

# 명령 갯수 인풋
T = int(input())

for _ in range(T):
    cmd = list(map(int, input().split()))

    match cmd[0]:
        case 1:
            deck.appendleft(cmd[1])
        case 2:
            deck.append(cmd[1])
        case 3:
            print(deck.popleft() if deck else -1)
        case 4:
            print(deck.pop() if deck else -1)
        case 5:
            print(len(deck))
        case 6:
            print(1 if not deck else 0)
        case 7:
            print(deck[0] if deck else -1)
        case 8:
            print(deck[-1] if deck else -1)

