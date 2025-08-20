# 팰린드롬인지 확인하기
##### 난이도: ***B3***
##### Link: https://www.acmicpc.net/problem/10988
##### Tag:  구현, 문자열
##### 풀이 일자: 2025년 8월 17일
***
## 문제 탐색하기
문자열을 입력받고,
해당 문자열이 앞으로도 배열했을 때랑 뒤로 배열했을때 일치하는지 확인하기
### 해결요소
1. 처음 input으로 문자열 입력받기
2. 반복문으로 문자열 거꾸로 저장하기 (reverse 활용도...!!)
3. 처음 문자열이랑 뒤집힌 문자열이랑 다르면 0, 모두 같다면 1을 반환
***
## 코드 설계하기
```
# 처음 입력받은 문자열을 리스트화
# 어차피 문자 하나 하나씩 접근하여 비교할 예정
s = list(input())

# 입력 받는 문자열을 거꾸로 반복하여 거꾸로 된 문자열을 형성
s_= []
for c in range(len(s)-1, -1, -1):
    s_.append(s[c])

# 또는
# 완벽한 복사본을 만들어 뒤집기
import copy
s_ = copy.deepcopy(s)
s_.reverse()

# 정상 문자열과 뒤집은 문자열을 비교, 어디 하나라도 다르면 0을 반환, 모두 같다면 1을 반환
for i in range(len(s)):
    if s[i] != s_[i]:
        return 0
    return 1
```
### 시간 복잡도
O(len(s)): 입력받은 문자열의 길이만큼 반복문 진행

***
## 시도 회차 수정사항

- 1회차
	- 단순 반복문으로 접근하여 거꾸로 된 문자열을 형성
- 2회차
    - 리스트의 reverse 메서드를 활용하여 거꾸로 된 문자열을 형성
    - 해당 과정시 완벽한 깊은 복사인 deepcopy를 활용
***
## 정답 코드
```
# 표준 입력 형성
import sys
input = lambda: sys.stdin.readline().rstrip()

import copy

def solution():
    # 문자열을 입력받아 리스트화 -> 문자 각각으로 활용!
    s = list(input())
    # 입력받은 문자열을 거꾸로 저장
    # s_= []
    # for c in range(len(s)-1, -1, -1):
    #     s_.append(s[c])

    # 딥카피로 완벽한 또 다른 복사본 형성 후 뒤집기
    s_ = copy.deepcopy(s)
    s_.reverse()
    
    # 두 문자열을 비교후 어디 하나라도 다르면 0을 return
    for i in range(len(s)):
        if s[i] != s_[i]:
            return 0
    # 모두 같다면 1을 return
    return 1

print(solution())
```