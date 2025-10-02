# https://www.acmicpc.net/problem/12865

# 표준 입력
import sys
from collections import deque
input = lambda: sys.stdin.readline().rstrip()


def solution():
    N = 4
    K = 7
    W = [6, 4, 3, 5]
    V = [13, 8, 6, 12]

    # 행: 무게, 열: 아이템
    values = [[0]*(N+1) for _ in range(K+1)]

    
    
    for weight in range(len(values)):
        for item in range(len(values[0])):
            values[weight][item] = (values[weight-W[item-1]][item-1]+V[])

            print('-'*30)

    return 0

    
solution()

    