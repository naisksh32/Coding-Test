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