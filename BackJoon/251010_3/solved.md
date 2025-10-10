# N-Queen
##### 난이도: ***G4***
##### Link: https://www.acmicpc.net/problem/9663
##### Tag: 브루트포스 알고리즘, 백트래킹
##### 풀이 일자: 2025년 10월 10일
***
## 문제 탐색하기
재귀함수를 통한 백트래킹 구현으로, 퀸이 놓일 수 있는 경우를 모두 탐색하자

### 해결요소
1. 퀸을 배치한다 -> 퀸의 공격범위를 설정한다 -> 공격범위에서 벗어난 좌표들 중 새로운 퀸을 배치한다 -> (반복) -> N개의 퀸을 모두 배치한다 -> 케이스 갯수를 1 증가시킨다 -> 다음 좌표를 탐색한다. 
***
## 코드 설계하기
```
# 체스판 위 퀸이 올라갈 열 좌표를 기록할 배열
arr = [-1 for _ in range(N)]
cnt = 0

# 각 요소별로 공격범위를 확인
attack_col = [False for _ in range(N)]      # 열 방향으로 공격
attack_Ldash = [False for _ in range(2*N-1)]    # \ 왼쪽 위에서 오른쪽 아래로 내리는 대각선 방향으로 공격
attack_Rdash = [False for _ in range(2*N-1)]    # / 왼쪽 아래에서 오른쪽 위로 올리는 대각선 방향으로 공격
----------------------------------------------------------------------------------------------------------
# k번째 퀸의 위치를 결정할 재귀함수
def func(k):
    
    global cnt
    
    # 만약 모든 퀸 배치에 성공을 했다.
    if k == N:
        cnt += 1
        return  # 함수 종료
    
    # 모든 칸을 탐색하기
    for i in range(N):
        
        # 만약 말이 공격 좌표에 없다면
        if not(attack_col[i]) and not(attack_Rdash[k+i]) and not(attack_Ldash[k-i+N-1]):
            
            # 해당 좌표에 말을 저장
            arr[k] = i
            
            # 그리고 공격범위 표시
            attack_col[i] = True
            attack_Rdash[k+i] = True
            attack_Ldash[k-i+N-1] = True
            
            # 다음 자리 탐색
            func(k+1)
            
            # 초기화
            attack_col[i] = False
            attack_Rdash[k+i] = False
            attack_Ldash[k-i+N-1] = False
----------------------------------------------------------------------------------------------------------
# 첫번째 퀸 부터 배치
func(0)
print(cnt)
```
### ★★★시간 복잡도★★★
##### O(N!)
최악의 경우  
첫번째 행에 올라갈 수 있는 퀸의 자리 N가지  
두번째 행에 올라갈 수 있는 퀸의 자리 N-1가지  
...  
N번째 행에 올라갈 수 있는 퀸의 자리 1가지  
=> Nx(N-1)x(N-2)x ... x2x1 = N!
***
## 시도 회차 수정사항
- 퀸을 배치하는 방식에서 열(세로줄) 공격범위와 행(가로줄) 공격범위는 쉽게 파악
- 대각선 방향 공격 ↗ 방식은 두 좌표의 합이 일정, ↘ 방식은 두 좌표의 차가 일정 한 방식으로 해결

***
## 정답 코드
```
# 표준 입력
import sys

key_in = lambda: sys.stdin.readline().rstrip()

N = int(key_in())


# 체스판 위 퀸이 올라갈 열 좌표를 기록할 배열
arr = [-1 for _ in range(N)]
cnt = 0

# 각 요소별로 공격범위를 확인
attack_col = [False for _ in range(N)]      # 열 방향으로 공격
attack_Ldash = [False for _ in range(2*N-1)]    # \ 왼쪽 위에서 오른쪽 아래로 내리는 대각선 방향으로 공격
attack_Rdash = [False for _ in range(2*N-1)]    # / 왼쪽 아래에서 오른쪽 위로 올리는 대각선 방향으로 공격


# k번째 퀸의 위치를 결정할 재귀함수
def func(k):
    
    global cnt
    
    # 만약 모든 퀸 배치에 성공을 했다.
    if k == N:
        cnt += 1
        return  # 함수 종료
    
    # 모든 칸을 탐색하기
    for i in range(N):
        
        # 만약 말이 공격 좌표에 없다면
        if not(attack_col[i]) and not(attack_Rdash[k+i]) and not(attack_Ldash[k-i+N-1]):
            
            # 해당 좌표에 말을 저장
            arr[k] = i
            
            # 그리고 공격범위 표시
            attack_col[i] = True
            attack_Rdash[k+i] = True
            attack_Ldash[k-i+N-1] = True
            
            # 다음 자리 탐색
            func(k+1)
            
            # 초기화
            attack_col[i] = False
            attack_Rdash[k+i] = False
            attack_Ldash[k-i+N-1] = False

# 첫번째 퀸 부터 배치
func(0)
print(cnt)
```