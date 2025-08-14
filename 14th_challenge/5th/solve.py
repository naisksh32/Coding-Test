# 표준 입력 형성
import sys
input = lambda: sys.stdin.readline().rstrip()

def solution():
    n = int(input()) 
    A = list(map(int, input().split(" ")))
    max_ =  A[0]
    min_ = A[0]
    for i in A:
        if i > max_:
            max_ = i
        if i < min_:
            min_ = i
    return min_, max_

def solution2():
    n = int(input())
    A = list(map(int, input().split(" ")))
    max_ =  max(A)
    min_ = min(A)
    return min_, max_    
    
a, b = solution()
print(a, b)