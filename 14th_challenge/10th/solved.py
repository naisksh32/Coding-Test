# 표준 입력 형성
import sys
input = lambda: sys.stdin.readline().rstrip()

def solution():
    # 숫자들을 담을 빈 리스트 생성
    nums = []

    # 5회 반복하며 배열을 완성해나감
    for _ in range(5):
        num = int(input())
        nums.append(num)

    # 완성된 배열을 정렬
    nums.sort()

    # 평균, 중앙값 구하기
    avg = int(sum(nums)/5)
    mid = nums[2]

    return avg, mid

a, b = solution()

# 표준 출력
print(a)
print(b)