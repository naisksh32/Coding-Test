T = int(input())

def solve():
    N, B = map(int, input().split())
    heights = list(map(int, input().split()))

    is_used = [False] * N
    result = []

    # 재귀함수
    def func(seq=0, top=0):
        # 끝내는 조건
        if top >= B:
            height = 0
            for k in range(N):
                height += heights[k]*is_used[k]
            result.append(height-B)
            return
        
        # 재귀 조건
        for i in range(seq, N):
            if not is_used[i]:

                is_used[i] = True
                top += heights[i]

                func(i, top)

                is_used[i] = False
                top -= heights[i]

    func()
    return min(result)

for _ in range(T):
    answer = solve()
    print(f'#{_+1} {answer}')