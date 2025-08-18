# 표준 입력 형성
import sys
input = lambda: sys.stdin.readline().rstrip()

def solution():
    s = input()
    s = s.strip().split(" ")

    if s == ['']:
        return 0
    
    return len(s)

print(solution())
