# 표준 입력 형성
import sys
input = lambda: sys.stdin.readline().rstrip()

def solution():
    N = int(input())
    for i in range(N):
        digit = []
        k = i
        while True:
            if k < 10:
                digit.append(k)
                break
            
            n1 = k%10
            digit.append(n1)
            k= int((k-n1)/10)
            
        if sum(digit) + i == N:
            return i
    
    return 0
    

print(solution())

