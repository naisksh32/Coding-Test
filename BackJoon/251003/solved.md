# 제로
##### 난이도: ***S4***
##### Link: https://www.acmicpc.net/problem/10773
##### Tag:  구현, 자료구조, 스택
##### 풀이 일자: 2025년 10월 3일
***
## 문제 탐색하기
자료구조 stack을 활용하여 모임통장을 만들어라

### 해결요소
1. 주어진 입력값대로 하나씩 넣는다.
2. 만약 입력값이 0이라면 맨 위에서 1개를 뺀다 => **스택** 자료구조
***
## 코드 설계하기
```
# 스택 자료구조인 wallet 배열을 생성
wallet = []

# 만약 입력된 값이 0이면 맨 위에서 1개를 뺌
if money == 0:
	wallet.pop()

# 0이 아니라면 그 돈을 추가
else:
	wallet.append(money)

# 모든 입력이 끝나고 배열안 모든 요소의 합
sum(wallet)
```
### ★★★시간 복잡도★★★
O(1): 주어진 입력값에 따라 추가하거나 or 빼거나 진행, (어느케이스든) 마지막에 합연산 공통으로 진행

***
## 시도 회차 수정사항
- 처음 0을 입력받는 경우? => IndexError: 뺄 것이 없는데, 빼서 발생
- 하지만 처음부터 잘못 말하는 경우는 없었음
***
## 정답 코드
```
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

```