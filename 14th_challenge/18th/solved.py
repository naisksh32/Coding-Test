# 표준 입력 형성
import sys
input = lambda: sys.stdin.readline().rstrip()

def solution():
    n = int(input())
    pibonacci = [0, 1]

    for i in range(n-1):
        pibonacci.append(pibonacci[i] + pibonacci[i + 1])

    print(pibonacci[-1])

solution()

