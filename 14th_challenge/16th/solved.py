# 표준 입력 형성
import sys
input = lambda: sys.stdin.readline().rstrip()

T = int(input())
in_company = set()

for _ in range(T):
    name, cmd = input().split()

    if cmd == "enter":
        in_company.add(name)
    elif cmd == "leave":
        in_company.remove(name)

for i in sorted(in_company, reverse=True):
    print(i)