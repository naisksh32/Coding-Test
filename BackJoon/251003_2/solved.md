# 옥상 정원 꾸미기
##### 난이도: ***G5***
##### Link: https://www.acmicpc.net/problem/6198
##### Tag:  자료구조, 스택
##### 풀이 일자: 2025년 10월 3일
***
## 문제 탐색하기
stack 자료구조를 활용하여 보고싶은 빌딩의 갯수를 계산하자

### 해결요소
1. 빌딩에 높이에 따라 보이는 옥상정원의 갯수가 다르다. => stack을 활용하여 보이는 건물들만 keep
2. 횟수가 진행될 수록 보이는 옥상정원의 갯수가 늘어간다.  
(ex. 10, 3의 높이의 건물만 있을 때 10의 입장에서는 3만 보임.)  
(ex. 10, 5, 3의 높이의 건물만 있을 때 10의 입장에서는 5, 3만 보이고, 5의 입장에서는 3만 보임.)
3. 스택을 활용하여 제일 밑에는 큰 높이만 남아있게 push, pop을 구성
***
## 코드 설계하기
```
# 빌딩 높이를 담을 stack 리스트 생성
buildings = []
# 보이는 옥상정원의 갯수를 누적하기 위한 정답 변수
answer = 0

# ★★★ 스택 구조를 제일 밑에 가장 큰 높이부터 내림차순으로 정렬하기 위한 로직
while (len(buildings) != 0) and (buildings[-1] <= h):
	buildings.pop()		# pop을 통해 기존에 있던 작은 요소를 빼기

# 건물 추가하기 전, 보이는 빌딩의 갯수를 더하기 (건물이 추가됨에 따라 누적합으로 계산)
answer += len(buildings)
# 건물 추가하기
buildings.append(h)
```
### ★★★시간 복잡도★★★
##### O(N)
반복문이 N번 실행, while문도 최악의 경우 N번 실행.  
그런데 pop은 한 원소가 스택에 push → 한 번만 pop 되므로, 전체 실행 과정에서 pop은 최대 n번.

***
## 시도 회차 수정사항
- 모든 빌딩을 입력받고, 한차례씩 이중 반복문으로 계산 => 값은 나오되, 시간이 너무 오래 걸림 (time_out)
- 그래서 stack 자료구조를 활용하면서, 빌딩들을 추가함과 동시에 보이는 건물 갯수를 누적해서 계산
***
## 정답 코드
```
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
```