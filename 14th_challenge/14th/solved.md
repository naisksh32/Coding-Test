# 큐2
##### 난이도: ***S4***
##### Link: https://www.acmicpc.net/problem/18258
##### Tag:  자료 구조, 큐
##### 풀이 일자: 2025년 8월 23일
***
## 문제 탐색하기
큐 자료구조를 이해하고,
여러가지 기능(push, pop, size, empty, front, back) 구현
### 해결요소
1. 스택이랑 다르게, 큐 자료구조형을 형성하는 dequeue 모듈 임포트
2. dequeue를 사용하여 해당 기능들을 구현
***
## 코드 설계하기
```
# 자료 추가
case "push":
	queue.append(cmd[1])

# 자료 제거
case "pop":
	print(queue.popleft() if queue else -1)

# 자료 크기
case "size":
	print(len(queue))

# 자료 유무
case "empty":
	print(0 if queue else 1)

# 제일 앞 자료
case "front":
	print(queue[0] if queue else -1)

# 제일 뒷 자료
case "back":
	print(queue[-1] if queue else -1)    
```
### 시간 복잡도
O(n): 명령어를 수행하는 것은 1, 명령어의 길이 n 만큼 반복

***
## 시도 회차 수정사항

- dequeue모듈을 사용하지 않고 똑같이 풀이하였더니, 답은 맞지만 채점 시 시간 초과 에러가 발생
- 따라서 collection의 dequeue 모듈을 임포트 하고 사용하니 제한 시간 내 채점 완료
***
## 정답 코드
```
# 표준 입력 형성
import sys
input = lambda: sys.stdin.readline().rstrip()

# 큐 자료형 생성
from collections import deque
queue = deque()

# 반복할 명령어 수
T = int(input())

for _ in range(T):
    cmd= input().split()
        
    match cmd[0]:   
        # 자료 추가
        case "push":
            queue.append(cmd[1])

		# 자료 제거
        case "pop":
            print(queue.popleft() if queue else -1)
        
        # 자료 크기
        case "size":
            print(len(queue))
        
        # 자료 유무
        case "empty":
            print(0 if queue else 1)
        
        # 제일 앞 자료
        case "front":
            print(queue[0] if queue else -1)
        
        # 제일 뒷 자료
        case "back":
            print(queue[-1] if queue else -1)    

```