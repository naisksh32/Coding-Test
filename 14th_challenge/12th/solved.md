# 분해합
##### 난이도: ***B2***
##### Link: https://www.acmicpc.net/problem/2231
##### Tag:  브루드포스(완전탐색)
##### 풀이 일자: 2025년 8월 22일
***
## 문제 탐색하기
어떤 수가 주어졌을 때,
그 수를 만들기 위해 또 다른 어떤수와 그 수의 자리수의 합 구하기
### 해결요소
1. 1부터 가능한 모든 경우를 탐색
2. 임의의 수를 1의 자리, 10의 자리, 100의 자리~ 로 분해하기
3. 각 자리수의 합과 그 수를 더해서 처음 수와 같으면, 그 수를 return
4. 반복을 다 돌았는데도 없으면 0을 return
***
## 코드 설계하기
```
#목표수 설정
N = int(input())

# 최대 목표수까지 1씩 키워 탐색
for i in range(N):

# 자릿수를 담는 로직
while True:
    # 만약 입력된 숫자가 한자리수면, 한자리수를 자릿수에 닮고 탈출
	if k < 10:
		digit.append(k)
		break

	# 10으로 나눠 1의 자리수 구하기        
	n1 = k%10
	# 1의 자리수 저장
	digit.append(n1)
	# 1의 자리수 빼고 10으로 나눠 그다음 숫자 만들기
	k= int((k-n1)/10)
	
	# 만약 목표수를 달성했다면, 그 수를 return
	if sum(digit) + i == N:
		return i
    

```
### 시간 복잡도
O(n): 임의의 숫자 N만큼 차례대로 반복문 계산

***
## 시도 회차 수정사항

- 자릿수를 구하는 과정에서 어떤 양의 숫자가 들어오더라도 계산할 수 있게 일의 자리부터 순차적으로 자릿수를 구함
- 이후 계속 반복되는 로직을 구현
***
## 정답 코드
```
# 표준 입력 형성
import sys
input = lambda: sys.stdin.readline().rstrip()

def solution():
    N = int(input())
    for i in range(N):
        digit = []
        k = i
        while True:
            if k < 10:
                digit.append(k)
                break
            
            n1 = k%10
            digit.append(n1)
            k= int((k-n1)/10)
            
        if sum(digit) + i == N:
            return i
    
    return 0

print(solution())
```