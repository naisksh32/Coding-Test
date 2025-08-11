# 정확성 테스트 통과, BUT 효율성 테스트 실패

# 덜 매운 음식을 섞어 매운음식으로 만드는 함스
def sum_sco(scoville):
    scoville.sort()
    scoville.append(scoville.pop(0) + scoville.pop(0) * 2)
    return scoville

# 정답이 되는 함수
def solution(scoville, K):
    # 변수 설정
    cnt = 0             # 합치는 횟수를 계산하는 변수 설정
    is_change = False    # 계속 합칠껀지 플래그 변수 설정
    
    # (0) 조건을 만족할 때까지 반복 시작
    while True:
        # 모든 원소에 대해서 검증
        for i in scoville:
            # 만약 하나라도 K 미만이면
            if i < K:
                is_change = True    # 바꾸기 장치 ON(True)
                break   # 원소비교를 그만하고 반복문을 탈출하여 그 다음 바꾸기 진행
        
        # 만약 바꾸기가 True고 합칠 원소가 2개이상 남아있다면
        if is_change and len(scoville) >= 2:
            scoville = sum_sco(scoville)    # 합치기 함수 작동
            is_change = False   # 바꾸기는 다시 OFF(False)로
            cnt += 1            # 바꾼 횟수 +1
            continue            # 그리고 처음(0)부터 다시 원소 비교
        
        # 만약 바꾸기가 True이지만, 합칠 원소가 1개만 남았다면
        elif is_change and len(scoville) == 1:
            return -1   # 조건을 만족시킬 수 없으므로 -1 return
        
        # 만약 바꾸지 않고, 모든 원소가 K 이상이라면
        else:
            return cnt  # 결과 반환