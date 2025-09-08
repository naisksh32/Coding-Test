# 가장 많이 받은 선물
##### 난이도: ***Lv 1***
##### Link: https://school.programmers.co.kr/learn/courses/30/lessons/258712
##### Tag: 이중 리스트
##### 풀이 일자: 2025년 9월 8일
***
## 문제 탐색하기
- 선물을 주고 받은 내역을 이중리스트화 시켜서 관리하기

### 해결요소
1. 텍스트 기반 저번 달 선물 거래 내역을 표로 만들어서 이중 리스트화 시키기
2. 파생 리스트로 선물지수 구하기
3. 이번 달 선물을 받는 조건에 맞게끔 로직을 구현하기
***
## 코드 설계하기
```
# 1. 주문 내역을 리스트화 시키기
# A는 주는사람, B는 받는 사람
for i in range(len(friends)):
    # A가 B에게 주는 선물 리스트(0으로 초기화)
    A_to_B = [0 for _ in range(len(friends))]
        
    for j in range(len(friends)):
        A = friends[i]
        B = friends[j]
        # 해당 조합에 해당하는 주문 모두 탐색
        for item in gifts:
            # 만약 주문이 같다면
            if (A + ' ' + B ) == item:
                # 리스트에 요소 추가
                A_to_B[friends.index(B)] += 1
    # A에 해당한 리스트를 전체리스트에 추가 
    gift_list.append(A_to_B)
            

    
# 2. 선물지수 계산
gift_level = []
for i in range(len(friends)):
    give_cnt = sum(gift_list[i])
    take_cnt = 0
    
    for j in range(len(friends)):
        take_cnt += gift_list[j][i]

    gift_level.append(give_cnt - take_cnt)
    
# 3. 조건에 맞게 계산하기
take_gift = [0 for _ in range(len(friends))]
for i in range(len(friends)):
    for j in range(len(friends)):
        
        if gift_list[i][j] > gift_list[j][i]:
            take_gift[i] += 1
        # 선물지수 비교
        elif (gift_list[i][j] == gift_list[j][i]):
            if gift_level[i] > gift_level[j]:
                take_gift[i] += 1

print('최종', take_gift)
answer = max(take_gift)
```
### ★★★시간 복잡도★★★
O(O^n): 수도 없이 리스트를 계속 순회하였다.
***
## 시도 회차 수정사항
- 처음은 주어진 조건별로 파생 변수들을 한개 두개씩 만들다가 결국 조잡하게 되었다.
- 입출력 설명 예시를 보며, 차례대로 한개씩 구현을 하면서 문제를 풀어나갔다.
***
## 정답 코드
```
def solution(friends, gifts):
    
    # 선물을 주고 받은 갯수를 저장할 리스트
    gift_list = []
    
    # A는 주는사람, B는 받는 사람
    for i in range(len(friends)):
        # A가 B에게 주는 선물 리스트(0으로 초기화)
        A_to_B = [0 for _ in range(len(friends))]
        
        for j in range(len(friends)):
            A = friends[i]
            B = friends[j]
            # 해당 조합에 해당하는 주문 모두 탐색
            for item in gifts:
                # 만약 주문이 같다면
                if (A + ' ' + B ) == item:
                    # 리스트에 요소 추가
                    A_to_B[friends.index(B)] += 1
        # A에 해당한 리스트를 전체리스트에 추가 
        gift_list.append(A_to_B)
            
    print(gift_list)
    
    # 선물지수 계산
    gift_level = []
    for i in range(len(friends)):
        give_cnt = sum(gift_list[i])
        take_cnt = 0
        
        for j in range(len(friends)):
            take_cnt += gift_list[j][i]

        gift_level.append(give_cnt - take_cnt)
        
    print(gift_level)
    
    # 계산
    take_gift = [0 for _ in range(len(friends))]
    for i in range(len(friends)):
        for j in range(len(friends)):
            
            if gift_list[i][j] > gift_list[j][i]:
                take_gift[i] += 1
            # 선물지수 비교
            elif (gift_list[i][j] == gift_list[j][i]):
                if gift_level[i] > gift_level[j]:
                    take_gift[i] += 1

    print('최종', take_gift)
    answer = max(take_gift)
    return answer
```