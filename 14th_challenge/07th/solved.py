# 표준 입력 형성
import sys
input = lambda: sys.stdin.readline().rstrip()

import copy

def solution():
    # 문자열을 입력받아 리스트화 -> 문자 각각으로 활용!
    s = list(input())
    # 입력받은 문자열을 거꾸로 저장
    # s_= []
    # for c in range(len(s)-1, -1, -1):
    #     s_.append(s[c])

    # 딥카피로 완벽한 또 다른 복사본 형성 후 뒤집기
    s_ = copy.deepcopy(s)
    s_.reverse()
    
    # 두 문자열을 비교후 어디 하나라도 다르면 0을 return
    for i in range(len(s)):
        if s[i] != s_[i]:
            return 0
    # 모두 같다면 1을 return
    return 1

print(solution())