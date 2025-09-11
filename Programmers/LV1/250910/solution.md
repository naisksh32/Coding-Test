# 크레인 인형뽑기 게임
##### 난이도: ***Lv 1***
##### Link: https://school.programmers.co.kr/learn/courses/30/lessons/64061
##### Tag: 이중 리스트, 구현
##### 풀이 일자: 2025년 9월 10일
***
## 문제 탐색하기
- 2차원 배열로 맵을 형성하고, 집게가 내려가 인형을 뽑아 저장하는 것을 구현
- 뽑은 인형은 스택 자료형으로 관리되며, 맨 끝 2개가 같은 인형이면 사라지게 만들기

### 해결요소
1. 이중리스트로 구성된 feature를 맵으로 표현하기
2. 집게가 내려가면서 0이 아닌 숫자 뽑기
3. 뽑은 인형은 별도로 스택구조로 관리하기
***
## 코드 설계하기
```
# moves의 순서대로 열 탐방(가로방향)
for i in moves:
    # 모든 행을 탐색 (세로 방향)
    for j in range(len(board)):
        # 만약 집게를 내려서 0이 아닌 숫자에 도달
        if board[j][i-1] != 0:
            stacklist.append(board[j][i-1])  # 해당 숫자를 스택리스트에 추가
            board[j][i-1] = 0  # 그리고 그 숫자는 0으로 변경
        
        # 만약 스택 리스트가 2개 이상의 원소로 구성되고,
        if len(stacklist) > 1:
            # 끝의 2개의 원소가 같다면
            if stacklist[-1] == stacklist[-2]:
                # 끝의 2개 원소 삭제
                stacklist.pop(-1)
                stacklist.pop(-1)
                # 터트린 횟수 2회 추가
                answer += 2 
        
        break  # 인형을 뽑았으니 반복문 종료
```
### ★★★시간 복잡도★★★
O(moves*len(board)): 2차원 리스트 board를 탐색 (최악의 경우 전체 탐색) 
***
## 시도 회차 수정사항
- 스택 자료형에서 끝의 2개 원소가 같으면 터지는 로직 구현
- 2차원 리스트를 탐색하며 0이 아닌 원소를 만날때까지 반복
- 인형을 뽑아 넣었으면 **break**로 반복문 탈출
***
## 정답 코드
```
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
```