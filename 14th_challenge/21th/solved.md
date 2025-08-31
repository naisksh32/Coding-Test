# 정수 제곱근
##### 난이도: ***S4***
##### Link: https://www.acmicpc.net/problem/2417
##### Tag:  수학, 이분 탐색
##### 풀이 일자: 2025년 8월 31일
***
## 문제 탐색하기
어떠한 수가 주어졌을 때, 이의 정수 제곱근을 구하여라

### 해결요소
1. 하나씩 확인하기에는 시간이 너무 오래 걸린다. => 따라서 이분 탐색 기법 활용
2. 시작점을 0, 끝점을 입력수로 설정
3. 중간값은 시작점과 끝점의 평균
4. 중간값을 제곱한 값이 입력값보다 크면 끝점을 내리고, 작으면 시작값을 키워 이분탐색 실행
***
## 코드 설계하기
```
# 시작점과 끝점 설정
start = 0
end = n

# 시작점이 작을때만 반복 실행
while start <= end:
	mid = (start+end) // 2

	# 중간값 제곱이 원래 수보다 작으면
	if mid**2 < n:
		start = mid + 1		# 시작점 올리기
	
	# 중간값 제곱이 원래 수보다 크면
	else:
		end = mid -1		# 끝값 내리기
```
### ★★★시간 복잡도★★★
O(log2(n)): 리스트의 절반 절반씩 순회하며 탐색함으로, 기존 전체 탐색의 경우인 n보다 작은 값을 가짐 

***
## 시도 회차 수정사항
- 반복 탐색 횟수가 커지면 커질수록 이분탐색의 시간 절약은 빛을 발한다(로그 특징)
***
## 정답 코드
```
# 표준 입력
import sys
input = lambda: sys.stdin.readline().rstrip()

import math

def solution():
    n = int(input())
    
    start = 0
    end = n
    
    while start <= end:
        mid = (start+end) // 2
        
        if mid**2 < n:
            start = mid + 1
        else:
            end = mid -1
            
    print(start)
    
solution()
```