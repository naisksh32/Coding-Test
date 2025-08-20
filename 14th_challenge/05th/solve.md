# 최소, 최대
##### 난이도: ***B3***
##### Link: https://www.acmicpc.net/problem/10818
##### Tag:  1차원 배열
##### 풀이 일자: 2025년 8월 15일
***
## 문제 탐색하기
N개의 정수로 이루어진 배열을 탐색하여
가장 최솟값과 최댓값을 알아내 반환하기

### 해결요소
1. 처음 input수로 몇개의 숫자를 받아올건지 인지(C 같은 경우 배열의 크기 설정, Python은 무방?)
2. 해당 숫자 문자열을 받고, 이들을 정수형으로 변환하여 쪼갠 뒤 1차원 배열 형성
3. 해당 배열에서 가장 큰값과 가장 작은 값을 찾기
***
## 코드 설계하기
```
# 처음 값을 받아 배열의 크기를 설정
n = int(input()) 		# 파이썬은 가변크기의 배열임으로 괜찮을지도?

# 숫자로 구성된 문자열을 나누어 일차원 리스트 형성 
A = list(map(int, input().split(" ")))

# 배열의 첫번째값을 제일 큰값과 작은값으로 임시로 설정
max_ =  A[0]
min_ = A[0]

# 배열 안 요소들을 일일이 비교하여,
for i in A:
	# 기존의 max_값보다 크면 새로은 max_값 형성
	if i > max_:
		max_ = i
	# 기존의 min_값보다 작으면 새로운 min_값 형성
	if i < min_:
		min_ = i

# 내장 함수를 이용해 최댓값과 최솟값 구하기
max_ = max(A)
min_ = min(A)
```
### 시간 복잡도
O(2n): 주어진 배열의 크기만큼 반복문이 비교 동작 (max, min)
***
## 시도 회차 수정사항

- 1회차
	- 처음 주어지는 수는 배열의 크기를 설정하는 수(C에서 초기 배열 형성)
	- 주어진 숫자 문자열을 숫자 리스트로 변환(앞문제 기출)
	- 배열의 원소를 집어 반복문으로 각각 원소들과 비교하여 최댓값과 최솟값 비교!!

- 2회차
	- 내장함수 min, max 활용
***
## 정답 코드
```
# 표준 입력 형성
import sys
input = lambda: sys.stdin.readline().rstrip()

def solution():
    n = int(input()) 
    A = list(map(int, input().split(" ")))
    max_ =  A[0]
    min_ = A[0]
    for i in A:
        if i > max_:
            max_ = i
        if i < min_:
            min_ = i
    return min_, max_

def solution2():
    n = int(input())
    A = list(map(int, input().split(" ")))
    max_ =  max(A)
    min_ = min(A)
    return min_, max_    
    
a, b = solution()
print(a, b)
```