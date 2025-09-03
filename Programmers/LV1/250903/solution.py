def solution(wallet, bill):
    
    cnt = 0             # 접은 횟수를 카운트하는 변수
    is_input = False    # 지갑에 넣을 수 있는지 여부 판단

    while not is_input: # 지갑에 넣을 수 없다면 반복

        # 만약 지폐의 가장 긴 길이가 지갑의 긴 길이보다 짧고,
        # 지폐의 짧은 길이가 지갑의 짧은 길이보다 짧으면
        if (max(wallet) >= max(bill)) and (min(wallet) >= min(bill)):
            is_input = True     # 지갑에 넣을 수 있다고 판단
        
        # 지폐를 접어야 하는 상황
        else:
            cnt += 1                    # 접은횟수 +1
            temp_new = max(bill) // 2   # 가장 긴 길이 반으로 접기
    
            bill.pop(bill.index(max(bill)))     # 긴 길이의 정보 빼기
            bill.append(temp_new)               # 반으로 접은 길이 넣기
            continue    # 반복문 계속
    
    return cnt  # 접은 횟수 반환