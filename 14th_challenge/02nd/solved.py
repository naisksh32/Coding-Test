import sys
# 인풋 시스템 설정
input = lambda: sys.stdin.readline().rstrip()

def solution():
    n = int(input())
    sol = []
    
    for i in range(n):
        p = input()
        sol.append(p)
    
    for j in sol:
        a, b = list(map(int, j.split(" ")))
        print(a + b)

solution()