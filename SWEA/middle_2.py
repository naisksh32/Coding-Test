T = int(input())

def rotate_matrix():
    N = int(input())

    matrix = []
    for _ in range(N):
        row = list(map(int, input().split()))
        matrix.append(row)

    matrix_90 = []
    for i in range(N):
        row = []
        for j in range(N-1, -1, -1):
            row.append(matrix[j][i])
        matrix_90.append(row)

    maxtrix_180 = []
    for i in range(N):
        row = []
        for j in range(N-1, -1, -1):
            row.append(matrix_90[j][i])
        maxtrix_180.append(row)

    matrix_270 = []
    for i in range(N):
        row = []
        for j in range(N-1, -1, -1):
            row.append(maxtrix_180[j][i])
        matrix_270.append(row)

    return matrix_90, maxtrix_180, matrix_270

for _ in range(T):
    print(f'#{_+1}')
    matrix_90, maxtrix_180, matrix_270 = rotate_matrix()

    for i in range(len(matrix_90)):
        for j in range(len(matrix_90[i])):
            print(matrix_90[i][j], end='')
        print(' ', end='')
        for j in range(len(maxtrix_180[i])):
            print(maxtrix_180[i][j], end='')
        print(' ', end='')
        for j in range(len(matrix_270[i])):
            print(matrix_270[i][j], end='')
        print()
