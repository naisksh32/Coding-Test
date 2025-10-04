# 표준 입력
import sys

key_in = lambda: sys.stdin.readline().rstrip()


while True:
    sentence = key_in()
    # 문장을 마친다는 .을 만다면 반복문을 탈출
    if sentence == '.':
        break

    special_chars = []   # 괄호를 저장할 stack
    
    # 문장의 글자 한개씩을 돌아가면서 검사
    # 특수문자를 만나면 그 문자를 스택에 추가
    for char in sentence:
        match char:
            case '(':
                special_chars.append('(')
            case ')':
                special_chars.append(')')
            case '[':
                special_chars.append('[')
            case ']':
                special_chars.append(']')

        # 스택의 맨 위 2개를 확인해서 일치하면 2개를 pop
        if len(special_chars) >= 2:
            if (special_chars[-2] == '(' and special_chars[-1] == ')') or (special_chars[-2] == '[' and special_chars[-1] == ']'):
                special_chars.pop()
                special_chars.pop()
        
    if special_chars:
        print('no')
    else:
        print('yes')
