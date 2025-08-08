def solution(s, skip, index):
    
    answer = ''  # 정답을 담을 빈 문자열    
    a_to_z = [x for x in range(ord('a'), ord('z')+1)]  # a~z까지 아스키코드로 배열 생성
    
    # 문자열 s안 요소들에 대해 반복
    for p in s:
        cnt = index  # 건너뛸 횟수 지정
        k = ord(p)   # 문자 p에 대한 아스키코드
        
        while cnt:   # 카운트가 남아있으면 반복
            k += 1   # 문자열을 한칸 앞으로 전진
            
            # 만약 전진한 문자열이 a-z범위를 벗어나면
            if k not in a_to_z:
                k = ord('a')    # a로 설정
            
            # 만약 앞으로 한칸 간 문자가 skip에 있는 문자라면
            if chr(k) in skip:  
                continue  # 카운트를 세지 않고 다시 반복문 동작
                
            # 만약 앞으로 한칸 간 문자가 skip애 포함되지 않는다면
            else:  
                  cnt -= 1 # 카운트를 셈 (정상적으로 전진)
            
        answer += chr(k)    # 모두 움직인 문자를 정답 문자열에 추가
    
    # 모든 문자에 대해서 반복이 끝나면 정답 문자를 반환 
    return answer