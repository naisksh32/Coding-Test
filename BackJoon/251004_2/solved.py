# 표준 입력
import sys

key_in = lambda: sys.stdin.readline().rstrip()

# 주어진 막대기와 레이저의 입력
key = key_in()

# 과정을 저장할 stack list
machine = []

# 총 잘린 막대기의 갯수
sticks = 0

# 한차례 과정을 반복
for i in key:
    
    # stack에 요소를 추가
    machine.append(i)

    # 만약 stack의 길이가 2 이상이고,
    if len(machine)>=2:
        # 맨 마지막 전과, 맨 마지막이 () 쌍을 이룰 경우
        if machine[-2] == '(' and machine[-1] == ')':
                        
            # pop을 진행 => ()요소 제거
            machine.pop()
            machine.pop()

            # 막대기의 끝
            # 이전에 뺀 기록이 있다면 1
            if poped:
                sticks += 1
            
            # 레이저로 자르기
            # 이전에 뺀 기록이 없다면 막대기 갯수만큼
            else:    
                sticks += len(machine)
            
            # 직전에 pop을 진행했다고 표시
            poped = True
        
        # 만약 추가만 한 경우라면 pop은 진행 안했다고 표시
        else:
            poped = False
    
    else:
        poped = False

# 총 잘린 막대기의 갯수를 return
print(sticks)