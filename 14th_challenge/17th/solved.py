# 표준 입력 형성
import sys
input = lambda: sys.stdin.readline().rstrip()

def solution():
    n1 = int(input())
    card = list(map(int, input().split()))
    card.sort()
    n2 = int(input())
    check = list(map(int, input().split()))
    
    answer = []

    for i in check:
        start = 0
        end = len(card) - 1 

        while start <= end:
            mid = (start + end) // 2

            if i == card[mid]:
                answer.append(1)
                break
            elif i < card[mid]:
                end = mid - 1
            elif i > card[mid]:
                start = mid + 1

            if start > end:
                answer.append(0)
    
    return answer

a = solution()
for i in a:
    print(i, end=' ')