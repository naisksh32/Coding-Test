def solution(ingredient):
    stack = [] # 스택을 쌓을 배열
    check = 0  # 최종 햄버거 완성 갯수
    complete = [1, 2, 3, 1] # 완성 햄버거 배열
    
    # 재료 배열 속 재료들을 탐색
    for item in ingredient:
        stack.append(item) # 원소 한개를 스택 배열에 추가
        
        # 만약 스택 배열이 4개를 넘어가고, 끝부터 차례대로 4개가 완성 배열과 같다면
        if len(stack) >= 4 and stack[-4:] == complete:
            check += 1      # 완성 갯수 1 추가
            del stack[-4:]  # 완성한 재료들 제거
    
    answer = check
    return answer