# 피보나치 수
##### 난이도: ***B2***
##### Link: https://www.acmicpc.net/problem/2747
##### Tag:  수학, 구현, 다이나믹 프로그래밍
##### 풀이 일자: 2025년 8월 28일
***
## 문제 탐색하기
이전 항과 현재 항의 합을 다음항으로 결정하는 피보나치 수열을 구현하기
그리고 해당 수열에서 입력받은 index의 값을 구하기

### 해결요소
1. 이전 항과 현재 항의 합을 구해 다음 항으로 추가하는 로직 구현
2. n번째 항만 구하면 되기에 횟수 반복문을 설정
***
## 코드 설계하기
```
# 기본 피보나치 수열 형성
pibonacci = [0, 1]

# 반복문을 통해 피보나치 수열의 다음 값 추가
for i in range(n-1):
    pibonacci.append(pibonacci[i] + pibonacci[i + 1])

# 입력받은 index까지의 피보나치 수열 구현 후 맨 마지막값 출력
print(pibonacci[-1])
```
### ★★★시간 복잡도★★★
O(n): 주어진 index만큼 반복문을 돌려야 해서
***
## 시도 회차 수정사항
- 기본이 되는 첫번째, 두번째 항은 설정 후 3번째 항 부터 피보나치 수열 구현
- 입력받은 항목이랑 리스트의 순번은 1의 차이가 있으므로, 반복문을 (n-1)회 반복
***
## 정답 코드
```
# 표준 입력 형성
import sys
input = lambda: sys.stdin.readline().rstrip()

def solution():
    n = int(input())
    pibonacci = [0, 1]

    for i in range(n-1):
        pibonacci.append(pibonacci[i] + pibonacci[i + 1])

    print(pibonacci[-1])

solution()

```