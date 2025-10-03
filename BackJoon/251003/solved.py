# 표준 입력
import sys

key_in = lambda: sys.stdin.readline().rstrip()

# 처음 몇번을 입력 받을건지
k = int(key_in())

# 스택 자료구조인 wallet 배열을 생성
wallet = []

# 입력받은 횟수만큼 반복
for _ in range(k):
    money = int(key_in())
	
    if money == 0:
        wallet.pop()
    else:
        wallet.append(money)
        
print(sum(wallet))
