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