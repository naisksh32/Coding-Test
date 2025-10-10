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