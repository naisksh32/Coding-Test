# 숫자카드
##### 난이도: ***S5***
##### Link: https://www.acmicpc.net/problem/10815
##### Tag:  자료 구조, 정렬, 이분 탐색, 해시를 사용한 집합과 맵, 집합과 맵
##### 풀이 일자: 2025년 8월 27일
***
## 문제 탐색하기
주어진 카드배열을 가지고, 입력된 숫자 배열에서 카드배열에 존재하는 숫자는 1, 없는 숫자는 0으로 결과를 반환하기  
단, 빠르게 탐색하기 위하여 이분탐색을 활용
### 해결요소
1. 이분탐색을 활용하여, 시작점과 끝점을 설정
2. 반복문을 통하여 중간점을 결정한 뒤에 해당 중간점과 배열의 숫자를 비교
3. 같다면 1을 바로 return
4. 작다면 end포인트를 줄이기
5. 크다면 start포인트 키우기
6. 이 작업을 계속 반복하여 start점과 end점이 같아질때까지 작업하기
7. 만약 start랑 end가 역전되어도 값이 안찾아진다면 0을 return
***
## 코드 설계하기
```
# start랑 end 포인트 설정
start = 0
end = len(card) - 1 

# 반복문을 통하여 start랑 end가 역전될 때 까지 반복
while start <= end:
    # 중간점 설정
    mid = (start + end) // 2

    # 중간점과 일치하면 일치하는 카드가 있다고 반환
    if i == card[mid]:
        answer.append(1)
        break   # 값을 찾았으니 반복문 탈출
    
    # 만약 중간점보다 작다면
    elif i < card[mid]:
        end = mid - 1       # end 포인트 줄이기

    # 중간점보다 크다면 
    elif i > card[mid]:
        start = mid + 1     # start 포인트 옮기기

    # start랑 end가 역전이 됬다면
    if start > end:
        answer.append(0)    # 없다고 0을 반환
```
### ★★★시간 복잡도★★★
이분 탐색 시간복잡도 : O(log2 N)
- 절반에서 찾기 (N/2)
- 또 절반에서 찾기 (N/2)
- 또 또 절반에서 찾기 (N/2)
- 결과: (N/2)^k = 1    // k = log2(N)
***
## 시도 회차 수정사항

- 기존 리스트 탐색은 한개의 요소 하나씩을 탐색하며 결과를 반환하기 때문에 시간이 오래 걸린다.
- 이분탐색을 활용하면 절반을 탐색 안해도 됨으로 시간적 측면에서 유리하다.
- 따라서 시작점과 끝점을 설정하고 옮기는 이분탐색 활용
***
## 정답 코드
```
# 표준 입력 형성
import sys
input = lambda: sys.stdin.readline().rstrip()

def solution():
    n1 = int(input())
    card = list(map(int, input().split()))
    card.sort()
    n2 = int(input())
    check = list(map(int, input().split()))
    
    answer = []

    for i in check:
        start = 0
        end = len(card) - 1 

        while start <= end:
            mid = (start + end) // 2

            if i == card[mid]:
                answer.append(1)
                break
            elif i < card[mid]:
                end = mid - 1
            elif i > card[mid]:
                start = mid + 1

            if start > end:
                answer.append(0)
    
    return answer

a = solution()
# 표준 출력
for i in a:
    print(i, end=' ')
```