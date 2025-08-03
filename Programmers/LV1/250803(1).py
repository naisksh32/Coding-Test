def solution(s):
    answer = []
    for i in range(len(s)):
        # 첫 시작점은 겹치는게 없으므로 무조건 -1
        if i == 0:
            answer.append(-1)
            
        # 해당 글자부터 앞으로 한개씩 차근차근 다가오기
        for j in range(i-1, -1, -1):

            # 다가오다 같은 글자가 있으면 몇번째 왔는지 추가
            if s[i] == s[j]:
                print(s[i], s[j])
                answer.append(i-j)
                break
            
            # 끝까지 왔는데도 겹치는 글자가 없으면 -1 추가
            if j == 0:
                answer.append(-1)

    return answer