# 대푯값2
##### 난이도: ***B2***
##### Link: https://www.acmicpc.net/problem/2587
##### Tag:  수학, 구현, 정렬, 사칙연산
##### 풀이 일자: 2025년 8월 20일
***
## 문제 탐색하기
주어진 배열을 입력받고,
배열을 오름차순으로 정렬한 후,
평균과 중앙값 구하기
### 해결요소
1. 주어진 배열을 입력받기
2. 입력받은 배열을 오름차순으로 정렬하기
3. 평균과 중앙값 구하기
***
## 코드 설계하기
```
# 5회 반복하며 5개의 배열 원소를 입력
for _ in range(5):
    num = int(input())
    nums.append(num)

# 완성된 배열을 정렬
nums.sort()

# 평균, 중앙값 구하기
avg = int(sum(nums)/5)
mid = nums[2]
```
### 시간 복잡도
O(5): 배열의 원소가 5개 임으로 5번 연산

***
## 시도 회차 수정사항

- 1회차
	- 리스트 sort() 매서드를 활용하여 배열 정렬
    - 배열 갯수가 5로 고정됨으로 5로 설정하는 하드코딩
    - 평균과 중앙값을 구하는 매서드가 없으므로 직접 구현
***
## 정답 코드
```
# 표준 입력 형성
import sys
input = lambda: sys.stdin.readline().rstrip()

def solution():
    # 숫자들을 담을 빈 리스트 생성
    nums = []

    # 5회 반복하며 배열을 완성해나감
    for _ in range(5):
        num = int(input())
        nums.append(num)

    # 완성된 배열을 정렬
    nums.sort()

    # 평균, 중앙값 구하기
    avg = int(sum(nums)/5)
    mid = nums[2]

    return avg, mid

a, b = solution()

# 표준 출력
print(a)
print(b)
```