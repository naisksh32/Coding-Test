# 차근 차근 1씩 올려서 세는 방법 => 시간이 너무 오래걸림
# 이분탐색 기법 (중간을 중심으로 해당 되는 쪽으로 절반씩 이동)
# ★ 시간 절약!!!

# 주어진 문제를 해결하는 함수
def sol(diffs, times, limit, level):
    tot_time =0		# 주어진 문제를 푸는데 걸리는 총 시간 변수 설정
    
    # 각 문제별로 풀이 진행
    for i in range(len(diffs)):
        # diff(난이도)가 level(숙련도) 보다 높아 틀리게 된 상황
        if diffs[i]>level:
                tot_time += (diffs[i] - level)*(times[i-1]+times[i]) + times[i]		# 자세한 식은 문제 참조
        
        # diff(난이도)가 level(숙련도) 보다 낮아 원래 소요시간 소요
        else:
            tot_time += times[i]
    
    # 만약 제한시간보다 덜 걸렸다면
    if tot_time <= limit:
        return True		# 문제 해결 -> level(수준) 낮춰도 되겠는데?
    else:
        return False	# 해결 못함 -> level(수준) 높이기
    

# 이분탐색을 적용하고자, 문제를 풀이하는 함수
def solution(diffs, times, limit):
    low = diffs[0]			# 최저 난이도 설정 (문제에서 0번째는 모두 난이도 1로 통일)
    high = max(diffs)	# 최고 난이도 설정
    
    # 최저점과 최고점이 같아질때 까지 반복
    while low <= high:
        mid = (high + low) // 2		# 중간점 설정

        result = sol(diffs, times, limit, mid)		# 중간 수준으로 문제풀이 진행
        
        if result:	# 성공했다?
            high = mid - 1		# 최고점 낮추기;
        else:	# 실패했다?
            low = mid + 1		# 최저점 높이기
    
    # 답은 최저점
    answer = low
    return answer

