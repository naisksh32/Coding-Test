def solution(cards1, cards2, goal):
    # 통합될 문장 리스트 설정
    tot_sentence = []
    
    # 목표를 맞추기 위해 goal 문자열 반복 
    for i in range(len(goal)):
        # 목표 문자가 1번 카드뭉치 제일 위에 있으면
        if goal[i] == cards1[0]:
            # 한 장을 빼서 최종 문장배열에 추가
            tot_sentence.append(cards1.pop(0))
            # 만약 빈 배열이면 0을 넣어서 배열 유지
            if cards1 == []:
                cards1.append(0)
        # 목표 문자가 2번 카드뭉치 제일 위에 있으면
        elif goal[i] == cards2[0]:
            # 한 장을 빼서 최종 문장 배열에 추가
            tot_sentence.append(cards2.pop(0))
            # 만약 빈 배열이면 0을 추가해서 배열 유지
            if cards2 == []:
                cards2.append(0)
    
    # 마지막 문장 확인
    if tot_sentence == goal:
        answer = 'Yes'
    else:
        answer = 'No'
    
    return answer