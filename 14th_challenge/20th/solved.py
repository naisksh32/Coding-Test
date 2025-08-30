# 표준 입력
import sys
input = lambda: sys.stdin.readline().rstrip()

def solution():
	answer = []		# 정답을 담을 배열
    
    # 입력 받기
	n = int(input())
	n_list = list(map(int, input().split()))
	m = int(input())
	m_list = list(map(int, input().split()))
    
	n_list.sort()	# 탐색을 위한 정렬

	# m_list의 요소 한개 한개씩을 탐색해서 존재하면 1, 없으면 0을 반환
	for i in m_list:
		# 이분 탐색을 위한 시작점과 끝 점 설정
		start = 0
		end = len(n_list) - 1

		# 시작점이 끝점보다 작을 때 마다 반복
		while start <= end:
		
			# 중간점은 시작점과 끝점의 평균
			mid = (start + end) // 2

			# n_list의 중간지점 값이랑 일치하면 존재한다고 판단
			if i == n_list[mid]:
				answer.append(1)
				break

			# 중간지점보다 크면 시작점을 중간점으로 이동
			elif i > n_list[mid]:
				start = mid + 1

			# 중간지점보다 작으면 끝점을 중간점으로 이동
			elif i < n_list[mid]:
				end = mid - 1

			# 시작점이 끝점을 뛰어 넘었을 때, 반복을 종료하며 숫자가 없다고 판단
			if start > end:
				answer.append(0)
				break
	
	# 표준 출력
	for k in answer:
		print(k)

solution()