# 회사에 있는 사람
##### 난이도: ***S5***
##### Link: https://www.acmicpc.net/problem/7785
##### Tag:  자료 구조, 해시를 사용한 집합과 맵, 집합과 맵
##### 풀이 일자: 2025년 8월 26일
***
## 문제 탐색하기
해시와 맵 자료구조를 이해하고, 해당 기능을 사용하여 기존 리스트와의 차별점 파악하기!!!  
비슷한 집합(set)에 대해서도 이해하기
### 해결요소
1. set를 활용하여 enter이면 집합에 추가, leave면 집합에서 제거 하는 방식으로 동작
***
## 코드 설계하기
```
# 회사 안 사람들의 집합
in_company = set()

# 주어진 입력을 이름과 명령으로 분리
name, cmd = input().split()

if cmd == "enter":          # 명령이 enter다?
    in_company.add(name)    # 집합에 추가
elif cmd == "leave":        # 명령이 leave다?
    in_company.remove(name) # 집합에 제거

# 집합을 이름 역순으로 정렬 후 한개씩 출력
for i in sorted(in_company, reverse=True):
    print(i)
```
### ★★★시간 복잡도★★★
최종 시간 복잡도 : O(Nlog(N))  
주어진 대상을 탐색 : O(1)  
주어진 대상을 추가 : O(1)  
주어진 대상을 제거 : O(1)  
집합을 역순으로 배열 : O(Nlog(N))
***
## 시도 회차 수정사항

- 기존 리스트로 문제풀이와 set로의 문제 풀이점 비교
- list는 탐색하고, 값을 추가하고, 제거하는데 O(N)만큼의 시간복잡도 필요
- set는 탐색하고, 값을 추가하고, 제거하는데 O(1)만킁의 시간복잡도 필요
- set는 해시함수로 주어진 값을 바로 찾아갈 수 있어서, 시간복잡도가 낮다
- 따라서 값의 추가 삭제가 빈번한 상황에서는 set자료형을 사용하는게 시간적 측면에서 유리하다
- (다만 해시테이블을 메모리에 올려두기 때문에 용량측면에선 다소 높다.)
***
## 정답 코드
```
# 표준 입력 형성
import sys
input = lambda: sys.stdin.readline().rstrip()

T = int(input())
in_company = set()

for _ in range(T):
    name, cmd = input().split()

    if cmd == "enter":
        in_company.add(name)
    elif cmd == "leave":
        in_company.remove(name)

for i in sorted(in_company, reverse=True):
    print(i)
```