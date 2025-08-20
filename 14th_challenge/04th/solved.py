# 표준 입력 형성
import sys
input = lambda: sys.stdin.readline().rstrip()

def solution():
    n = int(input())
    sum_ = 0
    for i in range(n+1):
        sum_ += i
    return sum_

def solution2():
    n = int(input())
    return int(((n)*(n+1))/2)

print(solution())