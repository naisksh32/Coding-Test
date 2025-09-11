def solution(board, moves):
    hit_cnt = 0
    collect = []
    
    for move in moves:
        j = move-1
        for i in range(len(board)):
            
            if board[i][j] != 0:
                doll = board[i].pop(j)
                board[i].insert(j, 0)
                collect.append(doll)
                collect, hit_cnt = pang(collect, hit_cnt)
                break

    return hit_cnt

# 같은 인형 2개를 모으면 사라지게 만드는 함수
def pang(collect, cnt):
    if len(collect) >= 2:
        if (collect[-1] == collect[-2]):
            collect.pop()
            collect.pop()
            cnt += 2
    
    return collect, cnt