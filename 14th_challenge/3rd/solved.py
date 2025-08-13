import sys
# 표준 입력 상태 설정
input = lambda: sys.stdin.readline().rstrip()

def solution():
    # 영수증 물건 가격 설정
    total_cost = int(input())
    # 물건 목록 갯수를 설정
    T = int(input())
    # 각 물건별 금액 리스트 형성
    sum_list = []

    for _ in range(T):  # 물건 목록별 반복
        # 가격과 갯수를 설정
        cost, nums = list(map(int, input().split(" ")))
        # 금액 리스트에다가 가격과 갯수의 곱을 추가
        sum_list.append(cost*nums)

    # 만약 물건들의 가격의 합이랑 영수증 가격이랑 같다면
    if sum(sum_list) == total_cost:
        return "Yes"    # Yse
    # 만약 물건들의 가격의 합이랑 영수증 가격이랑 다르다면
    else:
        return "No"     # No
    
print(solution())