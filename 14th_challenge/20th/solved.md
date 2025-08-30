# 수 찾기
##### 난이도: ***S4***
##### Link: https://www.acmicpc.net/problem/1920
##### Tag:  자료 구조, 정렬, 이분 탐색, 집합과 맵, 해시를 사용한 집합과 맵
##### 풀이 일자: 2025년 8월 30일
***
## 문제 탐색하기
n배열과 m배열을 입력받고, m배열의 원소가 n배열에 존재하면 1, 없으면 0을 return

### 해결요소
1. 빠른 탐색을 위한 이분탐색 설계하기
2. 이분탐색을 위한 시작점과 끝점 인덱스 설정
3. 중간값을 통하여 절반 절반씩 리스트를 순회
4. 최종 결과값을 반환
***
## 코드 설계하기
```
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
```
### ★★★시간 복잡도★★★
O(log2(n)): 리스트의 절반 절반씩 순회하며 탐색함으로, 기존 전체 탐색의 경우인 n보다 작은 값을 가짐 

***
## 시도 회차 수정사항
- 시작점과 끝점을 설정할 때, 값을 설정하는게 아닌 인덱스를 설정하는 것
- 중간값은 반복문을 진행하면서 그 사이에 계속 갱신하는 것
- 시작점이 끝점을 뛰어 넘었을 때, 이때는 숫자가 없다는 것으로 판단하고 반복문을 종료
***
## 정답 코드
```
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
```