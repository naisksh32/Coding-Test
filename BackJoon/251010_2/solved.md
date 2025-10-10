# N과 M (2)
##### 난이도: ***S3***
##### Link: https://www.acmicpc.net/problem/15650
##### Tag: 백트래킹
##### 풀이 일자: 2025년 10월 10일
***
## 문제 탐색하기
재귀함수를 통한 백트래킹 구현으로, 오름차순으로 정렬하는 경우의 수 탐색 (조합)

### 해결요소
1. 기존과 대부분 동일하지만, 오름차순으로 정렬해야 한다는 조건이 추가
2. 숫자를 탐색하는 지점에 있어 기존보다 높은 숫자만 탐색하도록 설정

***
## 코드 설계하기
```
arr = [0 for _ in range(M)]         # 숫자를 담을 바구니

# 재귀 입력으로 바구니의 몇 번째 칸(k)인지, 그리고 어디서부터 탐색(st_idx)하면 되는지를 인자로 받음
def func(k:int, st_idx:int=0):
    
    # 바구니가 꽉 찼다면
    if k == M:
        # 바구니 내용물을 출력
        for i in range(len(arr)):
            print(arr[i], end=' ')
        print()
        return  # 함수 종료

    # 숫자의 시작점부터 탐색
    for i in range(st_idx, N):
        # 바구니의 k번째 칸에는 (i+1)수를 저장
        arr[k] = i+1
        # 다음 칸에는 넣은 숫자보다 더 높은 숫자만 탐색
        func(k+1, i+1)

func(0)     # 바구니의 첫번째부터 넣을 숫자를 탐색
```
### ★★★시간 복잡도★★★
##### O( N C M ): 조합
조합의 방식으로 숫자를 추출
최악의 경우는 N=8, M=4일때 70의 시간복잡도를 가짐
***
## 시도 회차 수정사항
- 처음에는 기존 순열의 방식대로 조건을 추가하여 숫자를 넣을지 안넣을지 탐색
- 시간 복잡도를 줄이기 위해 조합의 방식을 채택 => 숫자 탐색 범위를 줄임
***
## 정답 코드
```
# 표준 입력
import sys

key_in = lambda: sys.stdin.readline().rstrip()

N, M = map(int, key_in().split())


arr = [0 for _ in range(M)]         # 숫자를 담을 바구니

# 재귀 입력으로 바구니의 몇 번째 칸(k)인지, 그리고 어디서부터 탐색(st_idx)하면 되는지를 인자로 받음
def func(k:int, st_idx:int=0):
    
    # 바구니가 꽉 찼다면
    if k == M:
        # 바구니 내용물을 출력
        for i in range(len(arr)):
            print(arr[i], end=' ')
        print()
        return  # 함수 종료

    # 숫자의 시작점부터 탐색
    for i in range(st_idx, N):
        # 바구니의 k번째 칸에는 (i+1)수를 저장
        arr[k] = i+1
        # 다음 칸에는 넣은 숫자보다 더 높은 숫자만 탐색
        func(k+1, i+1)

func(0)
```