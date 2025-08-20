# 영수증
##### 난이도: ***B4***
##### Link: https://www.acmicpc.net/problem/25304
##### Tag:  수학, 구현, 사칙연산
##### 풀이 일자: 2025년 8월 13일
***
## 문제 탐색하기
영수증에 적힌 값이랑 실제 계산한 값이랑 같은지 다른지 판단하기!

### 해결요소
1. input의 첫줄은 영수증 가격 금액 - 변수로 따로 저장
2. 두번째 줄은 물건 목록 갯수 - 반복 횟수 설정
3. 세번재 줄 부터 split을 통하여 숫자를 분리한 뒤 이 둘을 곱한값을 return
4. 각각의 물건 가격들을 list에 저장하여 나중에 sum을 통해 한번에 계산
5. 구한 가격이랑 영수증 가격이랑 비교하여 같으면 Yes, 다르면 No를 반환
***
## 코드 설계하기
```
# 기존 문제를 통하여 한번에 여러 자료를 입력받을 때 더 빠르게 입력 받는 방법 설정
import sys
input = lambda: sys.stdin.readline().rstrip()

# 첫출은 영수증 가격
total_cost = int(input())

# 두번째 줄은 반복할 횟수
T = int(input())

# 반복 횟수만큼 입력을 받고 텍스트를 분리한 뒤 값을 곱함
for _ in range(T):
    cost, nums = list(map(int, input().split(" ")))
    sum_list.append(cost*nums) # sum_list는 앞단에서 미리 선언

# 목록별 합한 금액이랑 영수증 금액이랑 같으면 Yes, 다르면 No 반환
if sum(sum_list) == total_cost:
    return "Yes"
else:
    return "No"

```
### 시간 복잡도
O(T), 변수 T 연산
연산 횟수는 input 받은 수(T)
***
## 시도 회차 수정사항

- 1회차
    - 처음 input의 유형을 탐색하여 변수를 설정하고, 그 다음 반복문, 마지막으로 조건문을 선정
    - 각 구문별 세부내용 작성
***
## 정답 코드
```
import sys
# 표준 입력 상태 설정
input = lambda: sys.stdin.readline().rstrip()

def solution():
    # 영수증 물건 가격 설정
    total_cost = int(input())
    # 물건 목록 갯수를 설정
    T = int(input())
    # 각 물건별 금액 리스트 형성
    sum_list = []

    for _ in range(T):  # 물건 목록별 반복
        # 가격과 갯수를 설정
        cost, nums = list(map(int, input().split(" ")))
        # 금액 리스트에다가 가격과 갯수의 곱을 추가
        sum_list.append(cost*nums)

    # 만약 물건들의 가격의 합이랑 영수증 가격이랑 같다면
    if sum(sum_list) == total_cost:
        return "Yes"    # Yse
    # 만약 물건들의 가격의 합이랑 영수증 가격이랑 다르다면
    else:
        return "No"     # No
    
print(solution())
```