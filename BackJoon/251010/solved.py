# 표준 입력
import sys

key_in = lambda: sys.stdin.readline().rstrip()

N, M = map(int, key_in().split())

# 숫자를 담을 바구니
arr = [0 for _ in range(M)]
# 해당 숫자가 사용 되었는지 확인
issued = [False for _ in range(N)]

# k번째 요소를 결정짓는 함수
def func(k):
    
    # 만약 Index Over, 즉 꽉 찼다면
    if k == M:
        # 바구니에서 요소들을 출력
        for i in range(M):
            print(arr[i], end=' ')
        print()
        # 그리고 함수를 종료
        return
    
    # k번째 자리에 맞는 숫자를 탐색
    for i in range(N):
        # 해당 숫자가 사용 되었는지 확인
        if not issued[i]:
            arr[k] = i+1		# 바구니의 k번째 자리에 해당 숫자를 넣음
            issued[i] = True	# 해당 숫자가 사용 되었다고 확인
            func(k+1)			# k+1번째, 즉 다음 차례의 숫자를 재귀로 확인
            issued[i] = False	# 출력까지 끝나 함수가 종료되면, 해당 숫자는 그 자리에서 역할을 다함
            

func(0)		# 0번째 자리부터 함수를 실행