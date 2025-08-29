# 표준 입력
import sys
input = lambda: sys.stdin.readline().rstrip()

def solution():
    n = int(input())

    if n == 1:
        print(1)
        return
    
    elif n == 2:
        print(2)
        return

    a, b = 1, 2  # tile[0], tile[1]
    for _ in range(3, n+1):
        a, b = b, (a+b) % 15746  # 매번 나머지 연산으로 overflow 방지

    print(b)

solution()
