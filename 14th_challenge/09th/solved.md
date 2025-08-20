# 수 정렬하기
##### 난이도: ***B2***
##### Link: https://www.acmicpc.net/problem/2750
##### Tag:  구현, 정렬
##### 풀이 일자: 2025년 8월 19일
***
## 문제 탐색하기
주어진 배열을 입력받고,
해당 배열을 작은 수부터 오름차순으로 정렬하기
### 해결요소
1. 주어진 배열을 입력받기
2. 입력받은 배열을 오름차순으로 정렬하기
***
## 코드 설계하기
```
# 배열의 원소 수 설정
T = int(input())

# 입력받을 배열 변수를 설정
list_ = []

# 주어진 원소 수 만큼 배열의 원소를 입력받음
for _ in range(T):
    num = int(input())
    list_.append(num)

# 배열을 오름차순으로 정렬
list_.sort()

# 표준 출력에 맞게 설정
for i in list_:
    print(i)
```
### 시간 복잡도
O(n^2): 주어진 배열에서 한개의 원소를 기준으로 한번 돌아야 함으로 n*n회 탐색

***
## 시도 회차 수정사항

- 1회차
	- 리스트 sort() 매서드를 활용하여 배열 정렬
***
## 정답 코드
```
# 표준 입력 형성
import sys
input = lambda: sys.stdin.readline().rstrip()

T = int(input())

def solution():
    list_ = []

    for _ in range(T):
        num = int(input())
        list_.append(num)

    list_.sort()

    return list_

for i in solution():
    print(i)

```