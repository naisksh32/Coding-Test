# 블랙잭
##### 난이도: ***B2***
##### Link: https://www.acmicpc.net/problem/2798
##### Tag:  브루드포스(완전탐색)
##### 풀이 일자: 2025년 8월 21일
***
## 문제 탐색하기
주어진 카드 배열을 입력받고,
카드들 중 3장을 뽑아서,
그 카드들의 합이 제시된 값을 넘지 않는 최대의 값 구하기
### 해결요소
1. 주어진 배열을 입력받기
2. 가능한 모든 조합의 카드의 경우 만들기(중첩 반복문 3번으로 구현)
3. 해당 조합에서 조건(천장치)을 비교하여 통과하기
4. 통과 되면, 그들 중에서 최댓값 찾기
***
## 코드 설계하기
```
# 입력값 설정
T, M = map(int, input().split(" "))				# 배열의 길이, 최대 숫자
cards = list(map(int, input().split(" ")))  # 입력 카드 배열 설정

# 변수 설정
card_max = 0   # 여러 조합들 중 조건에 맞게, 최대값을 구할 변수를 미리 설정

# 모든 반복을 통하여 모든 조합을 도출
for i in range(len(cards)):
	for j in range(i+1, len(cards)):
		for k in range(j+1, len(cards)):
			# 순차적으로 카드 3장을 저장 => 모든 경우의 수 모음 (중복조합 X)
			card_sum = [cards[i], cards[j], cards[k]]

# 카드 세장의 합과 M과 비교 하기
if sum(card_sum) <= M:

# 그동안 기록한 최댓값을 갱신했는지 비교하기
if sum(card_sum) > card_max:
	card_max = sum(card_sum) # 기록을 넘겼다면, 최댓값을 새로 지정
```
### 시간 복잡도
O(nC3): 카드가 5장인 경우 5C3 인 10번을 반복??

***
## 시도 회차 수정사항

- 중첩 반복문으로 어떻게 하면 모든 카드의 경우의 수를 구할지 고민 
- 카드의 경우의 수를 구하고, 조건과 비교하여 최고의 값을 낼 수 있는 방법을 고민
***
## 정답 코드
```
# 표준 입력 형성
import sys
input = lambda: sys.stdin.readline().rstrip()

def solution():
    # 입력값 설정
    T, M = map(int, input().split(" "))				# 배열의 길이, 최대 숫자
    cards = list(map(int, input().split(" ")))  # 입력 카드 배열 설정
    
    # 변수 설정
    card_max = 0   # 카드의 합의 최댓값을 저장할 인수
    
    # 모든 반복을 통하여 모든 조합을 도출
    for i in range(len(cards)):
        for j in range(i+1, len(cards)):
            for k in range(j+1, len(cards)):
                # 순차적으로 카드 3장을 저장
                card_sum = [cards[i], cards[j], cards[k]]
                
                # 카드 세장의 합과 M과 비교 하기
                if sum(card_sum) <= M:
                    # 그동안 기록한 최댓값을 갱신했는지 비교하기
                    if sum(card_sum) > card_max:
                        # 기록을 넘겼다면, 최댓값을 새로 지정
                        card_max = sum(card_sum)
        
	# 모든 탐색을 다 했다면 최댓값 반환
    return card_max

print(solution())
```