def solution(n, w, num):
    # 1. hxw 배열 형성
    boxes = []      # 박스를 담을 배열
    h = (n//w) + 1  # 행의 갯수
    box_num = 1     # 상자 번호
    
    # 박스 이중 리스트 만들기
    # ---------------------------------------
    # 행, 열별로 반복
    for i in range(h):
        box_line = []   # 한 줄의 박스 정보를 담을 리스트
        
        # 한 행 내부 로직 ---------------------------
        for j in range(w):
            # 박스 번호 부여하는 로직
            if box_num <= n:    # 주어진 박스 번호보다 작으면 1씩 늘려가며 추가
                box_line.append(box_num)
                box_num += 1
            else:               # 박스 번호를 넘어가면 넣지 않고 pass
                pass
        # 한 행 내부 로직 ---------------------------
        
        # 행마다 오름차순, 내림차순 번갈아 가면서 정렬
        box_line.sort(reverse=i%2)
        
        # 마지막 행에 대해서
        if len(box_line) != w:
            if i%2 == 0:  # 홀수 열일 때
                while len(box_line) != w:
                    box_line.append(0)      # 0을 뒤에다 추가

            else:         # 짝수 열일 때
                while len(box_line) != w:
                    box_line.insert(0, 0)   # 0을 앞에다 추가
        
        boxes.append(box_line)
    # ---------------------------------------

    for i in range(len(boxes)):
        if num in boxes[i]:
            print("행", i, "열", boxes[i].index(num))
            row = i
            column = boxes[i].index(num)
    
    target = []
    for _ in range(h):
        target.append(boxes[_][column])
    
    target.sort(reverse=True)

    answer = target.index(num) +1
    return answer