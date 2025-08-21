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
