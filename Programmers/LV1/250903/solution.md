# 지폐 접기
##### 난이도: ***Lv 1***
##### Link: https://school.programmers.co.kr/learn/courses/30/lessons/340199
##### Tag:  조건문, 반복문
##### 풀이 일자: 2025년 9월 3일
***
## 문제 탐색하기



### 해결요소
1. 상자의 배열을 이중리스트로 구현한다.
2. 해당 리스트에서 상자를 꺼내기 위한 갯수를 count 한다.
***
## 코드 설계하기
```
# 필요 변수 설정
cnt = 0      # 접은 횟수를 카운트하는 변수
wallet, bill = sorted(wallet), sorted(bill)  # 오름차순 정렬

# 반복문 조건: 가로세로중 어느 하나라도 지폐가 크면 반복
while wallet[0] < bill[0] or wallet[1] < bill[1]:
    
    bill[-1] //= 2      # 가장 긴 지폐 반으로 접기
    bill = sorted(bill) # 다시 오름차순 정렬
    cnt += 1            # 접은 횟수 1 추가
```
### ★★★시간 복잡도★★★
O(접은 횟수): 지폐를 접을 때 마다 리스트를 탐색해야 함으로 (근데 리스트도 2개로 짧아서) 
***
## 시도 회차 수정사항
- 긴 길이를 max, 짧은 길이를 min으로 설정해서 풀이
- 리스트를 sorted해서 앞을 min, 뒤를 max로 설정
***
## 정답 코드
```
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
```