# 표준 입력
import sys

key_in = lambda: sys.stdin.readline().rstrip()


N = 3
cost = [[26, 40, 83],
        [49, 60, 57],
        [13, 89, 99]]

# index
R, G, B = 0, 1, 2

# 첫번째 최솟값 -> 첫째 줄에서 가장 작은거
# 두번째 최솟값 -> (첫번째 최솟값에서 두번째 최솟값, )