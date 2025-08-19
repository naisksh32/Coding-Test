# 표준 입력 형성
import sys
input = lambda: sys.stdin.readline().rstrip()

T = int(input())

def solution():
    list_ = []

    for _ in range(T):
        num = int(input())
        list_.append(num)

    list_.sort()

    return list_

for i in solution():
    print(i)