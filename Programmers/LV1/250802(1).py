# 문자열 인덱싱으로 계산할려면 힘드니까
# 초로 전부 변환하여 연산 후 다시 분으로 문자열 포멧팅 진행

# 분 단위의 시간을 초 단위로 바꾸는 함수
def m_to_s(time):
    m, s =map(int, time.split(':'))		# map을 활용하여 문자열을 : 기준으로 슬라이싱 후 배정
    return m*60+s	# 분*60+초로 초 단위로 바꿈

# 문제를 해결하는 함수
def solution(video_len, pos, op_start, op_end, commands):
    # 분 단위의 시간들을 모두 초 단위로 바꿈
    video_s = m_to_s(video_len)
    pos_s = m_to_s(pos)
    ops_s = m_to_s(op_start)
    ope_s = m_to_s(op_end)
    
    # 만약 시작 지점이 오프닝 장소이면 오프닝 끝으로 이동
    if ops_s <= pos_s <= ope_s:
            pos_s = ope_s
    
    # 입력받은 커멘트 체크
    for c in commands:
        if c == 'next':		# Next 커멘드는 10초 뒤로
            pos_s = min(video_s, pos_s+10)
        elif c == 'prev':	# Prev 커멘드는 10초 앞으로
            pos_s = max(0, pos_s-10)
        
        # 이동한 위치가 오프닝 위치이면 오프닝 끝으로 이동
        if ops_s <= pos_s <= ope_s:
            pos_s = ope_s
		# 한 커멘드 끝
	# 모든 커멘드 끝

	# 다시 분 단위의 시간으로 바꾸기 위해 연산
    mm = pos_s // 60	# 60으로 나눈 몫이 분
    ss = pos_s % 60		# 60으로 나눈 나머지가 초
    
    answer = f'{mm:02d}:{ss:02d}'	# 문자열 포멧팅을 활용하여 원하는 형태로 반환
    return answer