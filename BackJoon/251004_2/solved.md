# 쇠막대기
##### 난이도: ***S2***
##### Link: https://www.acmicpc.net/problem/10799
##### Tag:  자료구조, 스택
##### 풀이 일자: 2025년 10월 4일
***
## 문제 탐색하기
stack 자료구조를 활용하여 레이저와 일반 막대기를 구분하고, 이에 따른 총 막대기의 갯수를 구해라

### 해결요소
1. 주어진 입력을 차례대로 stack으로 추가한다.
2. stack의 맨 뒤에 2개의 요소를 가지고 와서 () 괄호 한 쌍을 이루면 제거
3. 제거를 할 때 직전에 제거를 했는지 안했는지를 기준으로 raser인가 일반 막대기의 끝인가를 판단

***
## 코드 설계하기
```
# 과정을 저장할 stack list
machine = []

# 총 잘린 막대기의 갯수
sticks = 0

# 주어진 요소별로 반복
for i in key:
    
    # stack에 요소를 추가
    machine.append(i)

    # 만약 stack의 길이가 2 이상이고,
    if len(machine)>=2:
        # 맨 마지막 전과, 맨 마지막이 () 쌍을 이룰 경우
        if machine[-2] == '(' and machine[-1] == ')':
                        
            # pop을 진행 => ()요소 제거
            machine.pop()
            machine.pop()

            # 막대기의 끝
            # 이전에 뺀 기록이 있다면 1
            if poped:
                sticks += 1
            
            # 레이저로 자르기
            # 이전에 뺀 기록이 없다면 막대기 갯수만큼
            else:    
                sticks += len(machine)
            
            # 직전에 pop을 진행했다고 표시
            poped = True
        
        # 만약 추가만 한 경우라면 pop은 진행 안했다고 표시
        else:
            poped = False
    
    else:
        poped = False

# 총 잘린 막대기의 갯수를 return
print(sticks)
```
### ★★★시간 복잡도★★★
##### O(N)
반복문이 문장의 길이인 N번 수행. 괄호 문자안에 있는 요소별로 반복문이 진행. 최대 100,000번까지 진행

***
## 시도 회차 수정사항
- 처음 시도에는 직전 횟수를 어디에다 설정해야 되는지 모르고, 맨 위 기본에 설정하니, ()()같은 엣지케이스에서 오류
- 따라서 정확한 판단을 위해서, 조건문을 세세하게 나누고 이에 따라 직전에 잘랐는지 안잘랐는지 판단

***
## 정답 코드
```
# 표준 입력
import sys

key_in = lambda: sys.stdin.readline().rstrip()

# 주어진 막대기와 레이저의 입력
key = key_in()

# 과정을 저장할 stack list
machine = []

# 총 잘린 막대기의 갯수
sticks = 0

# 한차례 과정을 반복
for i in key:
    
    # stack에 요소를 추가
    machine.append(i)

    # 만약 stack의 길이가 2 이상이고,
    if len(machine)>=2:
        # 맨 마지막 전과, 맨 마지막이 () 쌍을 이룰 경우
        if machine[-2] == '(' and machine[-1] == ')':
                        
            # pop을 진행 => ()요소 제거
            machine.pop()
            machine.pop()

            # 막대기의 끝
            # 이전에 뺀 기록이 있다면 1
            if poped:
                sticks += 1
            
            # 레이저로 자르기
            # 이전에 뺀 기록이 없다면 막대기 갯수만큼
            else:    
                sticks += len(machine)
            
            # 직전에 pop을 진행했다고 표시
            poped = True
        
        # 만약 추가만 한 경우라면 pop은 진행 안했다고 표시
        else:
            poped = False
    
    else:
        poped = False

# 총 잘린 막대기의 갯수를 return
print(sticks)
```