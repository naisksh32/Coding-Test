# 합
##### 난이도: ***B5***
##### Link: https://www.acmicpc.net/problem/8393
##### Tag:  수학, 구현
##### 풀이 일자: 2025년 8월 14일
***
## 문제 탐색하기
자연수 n이 주어졌을 때, 1~n까지의 합 구하기

### 해결요소
1. input을 통해 n 받아오기
2. 1~n까지의 합 구하기
***
## 코드 설계하기
```
# 입력을 통해 n값 설정
n = int(input())

# n만큼 반복하면서 1씩 커진 i를 sum_에 더하기
for i in range(n+1):
    sum_ += i

# 1~n까지의 합 공식 사용
def solution2():
    n = int(input())
    return int(((n)*(n+1))/2)

```
### 시간 복잡도
1번 방법: O(n), n만큼 반복문 반복
2번 방법: O(1), 주어진 공식계산 1번
***
## 시도 회차 수정사항

- 1회차
    - n번 만큼 반복하며 i에다가 1씩 더해 합을 늘려감
    - 반복문 끝나는 시기를 n+1로 해야 함
- 2회차
    - 익숙한 공식을 return
    - 나눗셈 연산을 할때엔 float형을 반환함으로 int형변환이 필요(정답과 일치하려면)
***
## 정답 코드
```
# 표준 입력 형성
import sys
input = lambda: sys.stdin.readline().rstrip()

def solution():
    n = int(input())
    sum_ = 0
    for i in range(n+1):
        sum_ += i
    return sum_

def solution2():
    n = int(input())
    return int(((n)*(n+1))/2)

print(solution())
```