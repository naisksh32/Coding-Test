# 행렬 덧셈셈
##### 난이도: ***B3***
##### Link: https://www.acmicpc.net/problem/2738
##### Tag:  수학, 구현, 사칙연산산
##### 풀이 일자: 2025년 8월 16일
***
## 문제 탐색하기
NxM으로 구성된 배열을 입력받고,
두 행렬의 합 구하기기
### 해결요소
1. 처음 입력으로 N, M 배정 받기 (N이 행, M이 열)
2. 그 다음 인풋으로 행렬 A랑 B 지정하기
3. 입력받는 행렬 A와 B를 가지고 두 행렬의 합 C 구하기기
***
## 코드 설계하기
```
# 행렬의 행(N)과 열(M) 입력
N, M = map(int, input().split(" "))     # 늘 하던대로 나누기

# 입력받을 행렬 변수 미리 형성성
A = []  # 첫번째 행렬 A
B = []  # 두번째 행렬 B
C = []  # 두 행렬의 합 C

# A 행렬의 입력
for _ in range(N):
    a = list(map(int, input().split(" ")))  # 한 행의 요소를 받기
    A.append(a)     # A 배열에 한 행의 요소를 추가

# B 행렬의 입력
for _ in range(N):
    b = list(map(int, input().split(" ")))  # 한 행의 요소를 받기
    B.append(b)     # B 배열에 한 행의 요소를 추가

# 두 행렬의 합 구하기기
for i in range(N):
    c = []    # 임시로 한 행의 성분을 담을 리스트 설정
    for j in range(M):
        c.append(A[i][j] + B[i][j])     # 각 행의 원소를 추가
    C.append(c) # 완성된 행요소를 행렬의 합 배열 C에다가 한 행 추가

# 표준 입출력 맞추기
for i in range(len(C)):
    for j in range(len(C[i])):
        print(C[i][j], end=' ')     # 한 행의 원소들은 한칸 띄어서 출력
    print() # 행이 바뀌면 줄바꿈
```
### 시간 복잡도
O(max(N, M)): 주어진 행(N)or열(M)값들 중 큰 값으로 반복문 진행행
***
## 시도 회차 수정사항

- 1회차
	- 변수를 따로 따로 나눠서 설정하여 진행 (A행렬 따로, B행렬 따로)
    - 두 행렬의 합을 이중 반복문으로 구성해서 구하기
    - 마지막 표준 출력 관련해서 print() 내부 함수 고려
- 앞으로 고려해야 할 점
    - 한번에 A, B행렬 입력이 오는데, 이를 간단하게 할 방법
    - 한번에 계산 후 표준 출력으로 바꾸는 방법
***
## 정답 코드
```
# 표준 입력 형성
import sys
input = lambda: sys.stdin.readline().rstrip()

def solution():
    # 행렬의 행과 열 수 입력
    N, M = map(int, input().split(" "))
    A = []  # 첫번째 행렬 A
    B = []  # 두번째 행렬 B
    C = []  # 두 행렬의 합 C

    # A 행렬의 입력
    for _ in range(N):
        a = list(map(int, input().split(" ")))
        A.append(a)
    # B 행렬의 입력
    for _ in range(N):
        b = list(map(int, input().split(" ")))
        B.append(b)

    # 두 행렬의 합 구하기기
    for i in range(N):
        c = []
        for j in range(M):
            c.append(A[i][j] + B[i][j])
        C.append(c)
    
    # 표준 입출력 맞추기
    for i in range(len(C)):
        for j in range(len(C[i])):
            print(C[i][j], end=' ')
        print()

solution()
```