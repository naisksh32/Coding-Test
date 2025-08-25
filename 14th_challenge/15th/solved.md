# 덱2
##### 난이도: ***S4***
##### Link: https://www.acmicpc.net/problem/28279
##### Tag:  자료 구조, 덱
##### 풀이 일자: 2025년 8월 24일
***
## 문제 탐색하기
덱 자료구조를 이해하고,
다양한 기능들을 구현
### 해결요소
1. 앞전 큐 자료형과 비슷하게 dequeue 라이브러리를 임포트하여 기능을 구현
2. 이전 스택과 큐와 비교하여 큰 차이점이라면 자료를 넣고 빼는 것이 앞뒤로 모두 가능하다는 것
***
## 코드 설계하기
```
# 맨 앞에 자료를 추가
case 1:
    deck.appendleft(cmd[1])

# 맨 뒤에 자료를 추가
case 2:
    deck.append(cmd[1])

# 맨 앞에 자료를 빼기
case 3:
    print(deck.popleft() if deck else -1)

# 맨 뒤에 자료를 빼기
case 4:
    print(deck.pop() if deck else -1)

# 들어있는 자료의 갯수를 출력
case 5:
    print(len(deck))

# 빈 배열(empty)라면 1, 무언가 들어있으면 0을 출력
case 6:
    print(1 if not deck else 0)

# 자료의 첫번째 값을 출력
case 7:
    print(deck[0] if deck else -1)

# 자료의 마지막 값을 출력
case 8:
    print(deck[-1] if deck else -1)
```
### 시간 복잡도
O(n): 명령어를 수행하는 것은 1, 명령어의 길이 n 만큼 반복

***
## 시도 회차 수정사항

- dequeue모듈을 사용하여 한번에 해결(이전 큐와 비슷하다)
***
## 정답 코드
```
# 표준 입력 형성
import sys
input = lambda: sys.stdin.readline().rstrip()

# 덱 자료구조 생성
from collections import deque
deck = deque()

# 명령 갯수 인풋
T = int(input())

for _ in range(T):
    cmd = list(map(int, input().split()))

    match cmd[0]:
        case 1:
            deck.appendleft(cmd[1])
        case 2:
            deck.append(cmd[1])
        case 3:
            print(deck.popleft() if deck else -1)
        case 4:
            print(deck.pop() if deck else -1)
        case 5:
            print(len(deck))
        case 6:
            print(1 if not deck else 0)
        case 7:
            print(deck[0] if deck else -1)
        case 8:
            print(deck[-1] if deck else -1)
```