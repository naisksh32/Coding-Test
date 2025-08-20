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