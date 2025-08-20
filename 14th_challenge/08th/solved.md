# 단어의 갯수
##### 난이도: ***B2***
##### Link: https://www.acmicpc.net/problem/1152
##### Tag:  구현, 문자열
##### 풀이 일자: 2025년 8월 18일
***
## 문제 탐색하기
문자열을 입력받고,
문자열을 구성하는 단어의 갯수 파악
### 해결요소
1. 처음 input으로 문자열 입력받기
2. 받은 문자열에서 앞뒤 공백 제거(strip())
3. 공백으로 문자열 나눈 후 갯수 세기
***
## 코드 설계하기
```
# 문자열 입력 받기
s = input()

# 입력 받은 문자열의 앞뒤 공백을 제거하고(strip) 공백을 기점으로 단어 분리(split)
s = s.strip().split(" ")

# 만약 공백 한번만 입력됬을 경우 바로 return 0
if s == ['']:
    return 0

# 아니라면 단어의 갯수를 return
return len(s)
```
### 시간 복잡도
O(1): 문자열을 입력받고, 공백인지 확인하고, 공백을 기준으로 단어를 나누고, 갯수를 return 

***
## 시도 회차 수정사항

- 1회차
	- strip 매서드를 활용하여 앞뒤 공백 없애기
    - 이후 배열의 갯수를 파악해서 return
- 2회차
    - 예외 상황으로 공백 1개(" ")만 입력되었을 경우 고려
    - 해당 경우는 바로 0으로 결과 출력
***
## 정답 코드
```
# 표준 입력 형성
import sys
input = lambda: sys.stdin.readline().rstrip()

def solution():
    s = input()
    s = s.strip().split(" ")

    if s == ['']:
        return 0
    
    return len(s)

print(solution())

```