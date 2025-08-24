# 스택
##### 난이도: ***S4***
##### Link: https://www.acmicpc.net/problem/10828
##### Tag: 구현, 자료구조, 스택
##### 풀이 일자: 2025년 8월 23일
***
## 문제 탐색하기
스택을 구현하기 (push, pop, size, empty, top)
### 해결요소
1. 주어진 명령어 별로 스택에 해당하는 기능을 구현
## 코드 설계하기
```
# push: num을 스택에 추가
	case "push":
		stack.append(num)
# pop: 스택의 가장 위 요소를 제거, 그 수를 출력 // 만약 없는 경우에는 -1 출력
	case "pop":
		if stack == []:
			print(-1)
		else:
			print(stack.pop())
        
# size: 현재 스택의 길이를 출력
	case "size":
		print(len(stack))
        
# empty: 스택이 비어있으면 1, 아니면 0을 출력
	case "empty":
		if stack == []:
			print(1)
		else:
			print(0)
        
# top: 스택의 가장 위에 있는 정수를 출력 // 만역 없는 경우에는 -1 출력
	case "top":
		if stack == []:
			print(-1)
		else:
			print(stack[-1])
```
### 시간 복잡도
O(1): 주어진 명령을 순서대로 실행하기 때문

***
## 시도 회차 수정사항

- 스택의 특징을 이해하고, 각 메서드의 기능을 구현
- 따로 함수로 뺄 수 있는 부분은 빼기
***
## 정답 코드
```
# 표준 입력 형성
import sys
input = lambda: sys.stdin.readline().rstrip()

# 명령의 수 입력
T = int(input())

# 주어진 명령을 수행할 빈 배열 생성
stack = []

# 주어진 명령동안 반복
for _ in range(T):
    
    # 명령을 입력 받음
    command = input()
    
    # 만약 명령이 push(공백으로 나뉘는 경우)인 경우 공백으로 명령과 숫자를 분리
    if " " in command:
        command, num = command.split(" ")
        num = int(num)
    
    # 명령어의 분기마다 다음 행동을 실행    
    match command:
        # push: num을 스택에 추가
        case "push":
            stack.append(num)
        
        # pop: 스택의 가장 위 요소를 제거, 그 수를 출력 // 만약 없는 경우에는 -1 출력
        case "pop":
            if stack == []:
                print(-1)
            else:
                print(stack.pop())
        
        # size: 현재 스택의 길이를 출력
        case "size":
            print(len(stack))
        
        # empty: 스택이 비어있으면 1, 아니면 0을 출력
        case "empty":
            if stack == []:
                print(1)
            else:
                print(0)
        
        # top: 스택의 가장 위에 있는 정수를 출력 // 만역 없는 경우에는 -1 출력
        case "top":
            if stack == []:
                print(-1)
            else:
                print(stack[-1])
```