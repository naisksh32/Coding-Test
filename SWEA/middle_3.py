def func():
    N, M = map(int, input().split())

    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    # A가 B보다 길 경우 두 리스트를 교환
    if len(A) > len(B):
        A, B = B, A

    max_sum = 0
    for i in range(len(B) - len(A) + 1):
        current_sum = 0

        for j in range(len(A)):
            current_sum += A[j] * B[j + i]

        max_sum = max(max_sum, current_sum)

    return max_sum

T = int(input())

for _ in range(T):
    answer = func()
    print(f'#{_+1} {answer}')