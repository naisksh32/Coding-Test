# heapq를 사용하여 효율성 테스트 성공

import heapq  # 힙큐 모듈 사용

def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)     # scoville 배열을 힙큐로 만듦
    
    # scoville의 배열 원소가 2개 이상일때
    while len(scoville) >= 2:
        
        # 만약 제일 낮은 원소가 K 이상이면
        if scoville[0] >= K:
            return answer   # 바로 정답 반환
        
        first = heapq.heappop(scoville)     # 제일 낮은 첫번째 원소 추출
        second = heapq.heappop(scoville)    # 그다음 낮은 두번재 원소 추출
        assem = first + second * 2          # 합치기 공식 적용
        heapq.heappush(scoville, assem)     # scoville에 합친 원소를 힙큐로 추가
        answer += 1                         # 변경 count를 1 늘리기
    
    # scoville의 배열이 원소 1개를 가지고 있을 때,
    # 그 원소가 K 이상이면 answer반환, 그렇지 않다면 -1 반환
    return answer if scoville[0] >= K else -1