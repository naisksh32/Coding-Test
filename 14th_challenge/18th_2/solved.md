# 피보나치 수
##### 난이도: ***B2***
##### Link: https://www.acmicpc.net/problem/24416
##### Tag:  수학, 다이나믹 프로그래밍
##### 풀이 일자: 2025년 8월 28일
***
## 문제 탐색하기
재귀함수로 구현한 피보나치 수열이랑, DP로 구현한 피보나치 수열의
호출 횟수랑 연산 시간 비교하기

### 해결요소
1. 재귀함수는 계속 함수를 호출함으로 숫자가 커지면 커질수록 자신을 부르는 횟수가 많아진다.
2. DP는 기존 값들을 이용하고, 저장해서 앞으로의 값을 만들어 나아감으로 호출 횟수가 많이 줄어든다.
(정확히는 n-2번 호출 (처음 2개 제외))
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
재귀함수 시간복잡도: O(2^n)
     DP 시간 복잡도: O(n)
***
## 시도 회차 수정사항
- 재귀함수는 n이 1 또는 2일때 호출 카운트가 누적이 됨 (2^n)
- DP는 주어진 횟수만큼 딱 호출이 됨 (n-2)
***
## 정답 코드
```
# 답안 입력시 재귀함수의 timeover 문제로 외부에서 긁어 옮
import sys

def fib(n):
    f[1] = 1
    f[2] = 1

    for i in range(3, n + 1):
        f[i] = f[i - 1] + f[i - 2]

    return f[n]

def fibonacci(n):
    return n - 2

n = int(sys.stdin.readline())

f = [0] * (n + 1)

print(fib(n), end=' ')
print(fibonacci(n))
```