# 표준 입력
import sys

key_in = lambda: sys.stdin.readline().rstrip()
#

# 빌딩 갯수
n = int(key_in())

buildings = []
answer = 0

for i in range(n):
    h =  int(key_in())
    
	# 제일 밑에 가장 큰 높이부터 내림차순으로 정렬하기 위한 로직
    while (len(buildings) != 0) and (buildings[-1] <= h):
        buildings.pop()
    
	# 건물을 추가하기 전, 보이는 옥상정원의 갯수를 먼저 더하기!
    answer += len(buildings)
    buildings.append(h)
    
print(answer)