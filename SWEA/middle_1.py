T  = int(input())

def cal_flies():

    # 입력 받기
    N, M = map(int, input().split())

    matrix = []

    for _ in range(N):
        row = list(map(int, input().split()))
        matrix.append(row)


    max_flies = 0

    # 완전 탐색
    for i in range(N):
        for j in range(N):

            # 십자 모양
            ten_flies = 0
            ten_flies += matrix[i][j]
            for k in range(1, M):
                # 상
                if i - k >= 0:
                    ten_flies += matrix[i - k][j]
                # 하
                if i + k < N:
                    ten_flies += matrix[i + k][j]
                # 좌
                if j - k >= 0:
                    ten_flies += matrix[i][j - k]
                # 우
                if j + k < N:
                    ten_flies += matrix[i][j + k]
                
            # X 모양
            cross_flies = 0
            cross_flies += matrix[i][j]
            for k in range(1, M):
                # 좌상
                if i - k >= 0 and j - k >= 0:
                    cross_flies += matrix[i - k][j - k]
                # 우상
                if i - k >= 0 and j + k < N:
                    cross_flies += matrix[i - k][j + k]
                # 좌하
                if i + k < N and j - k >= 0:
                    cross_flies += matrix[i + k][j - k]
                # 우하
                if i + k < N and j + k < N:
                    cross_flies += matrix[i + k][j + k]

            max_flies = max(max_flies, ten_flies, cross_flies)

    return max_flies

for _ in range(T):
    answer = cal_flies()
    print(f'#{_+1} {answer}')