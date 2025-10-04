# 균형잡힌 세상
##### 난이도: ***S4***
##### Link: https://www.acmicpc.net/problem/4949
##### Tag:  자료구조, 문자열, 스택
##### 풀이 일자: 2025년 10월 4일
***
## 문제 탐색하기
stack 자료구조를 활용하여 괄호를 쌓고 이를 제대로 마무리 지었는지 확인하자

### 해결요소
1. 입력된 문자열을 처음부터 차례대로 분석하며 괄호 기호를 저장 해 둔다.
2. 2개 이상 입력되었을 순간부터, 마지막 2개의 요소를 확인해 () 혹은 []이 완성되면 stack에서 제거한다.
3. 최종적으로 문장이 끝났을 때 stack 리스트가 비어있으면 yes, 무언가 차 있으면 no로 return 한다.
***
## 코드 설계하기
```
# 문장을 계속해서 입력 받을 것이므로, while 반복문0
while True:

# 사용자로부터 문자열을 입력받음
sentence = key_in()

# 만약 .을 입력받으면 반복문을 탈출
if sentence == '.':
    break

# 괄호 문자를 저장할 리스트
special_chars = []
    
# 문장의 글자 한개씩 차례대로 순회하며, 괄호드을 추가
for char in sentence:
    match char:
        case '(':
            special_chars.append('(')
        case ')':
            special_chars.append(')')
        case '[':
            special_chars.append('[')
        case ']':
            special_chars.append(']')

# 만약 스택에 2개이상 요소가 있고, 이들이 (), []를 환성하면, 스택에서 제거
if len(special_chars) >= 2:
    if (special_chars[-2] == '(' and special_chars[-1] == ')') or (special_chars[-2] == '[' and special_chars[-1] == ']'):
        special_chars.pop()
        special_chars.pop()

# 스택이 비어있으면 yes, 무언가 차있으면 no를 반환  
if special_chars:
    print('no')
else:
    print('yes')
```
### ★★★시간 복잡도★★★
##### O(N)
반복문이 문장의 길이인 N번 수행. 최대 100글자까지 들어올 수 있으므로 최대는 O(100)의 시간복잡도를 가짐

***
## 시도 회차 수정사항
- 백준 입력에는 한 뭉텡이로 글이 있어 처음 입력을 ''' '''로 받아 엔터단위로 구분지음. 하지만 실제로는 한줄 한줄씩 입력이라 입력 방식을 수정

***
## 정답 코드
```
# 표준 입력
import sys

key_in = lambda: sys.stdin.readline().rstrip()


while True:
    sentence = key_in()
    # 문장을 마친다는 .을 만다면 반복문을 탈출
    if sentence == '.':
        break

    special_chars = []   # 괄호를 저장할 stack
    
    # 문장의 글자 한개씩을 돌아가면서 검사
    # 특수문자를 만나면 그 문자를 스택에 추가
    for char in sentence:
        match char:
            case '(':
                special_chars.append('(')
            case ')':
                special_chars.append(')')
            case '[':
                special_chars.append('[')
            case ']':
                special_chars.append(']')

        # 스택의 맨 위 2개를 확인해서 일치하면 2개를 pop
        if len(special_chars) >= 2:
            if (special_chars[-2] == '(' and special_chars[-1] == ')') or (special_chars[-2] == '[' and special_chars[-1] == ']'):
                special_chars.pop()
                special_chars.pop()
        
    if special_chars:
        print('no')
    else:
        print('yes')

```