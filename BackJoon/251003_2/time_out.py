# 표준 입력
import sys

key_in = lambda: sys.stdin.readline().rstrip()

# 빌딩 갯수
building_num = int(key_in())

# 각 빌딩 높이
building_height = []

for _ in range(building_num):
    building_height.append(int(key_in()))

# 각 위치에서 바라볼 수 있는 옥상 수
see_proofs = []

for master_idx in range(building_num):
    main_height = building_height[master_idx]
    cnt = 0
    
    for idx in range(master_idx+1, building_num):
        compare_height = building_height[idx]
        
        if main_height > compare_height:
            cnt += 1
        else:
            break
    
    see_proofs.append(cnt)
    
print(sum(see_proofs))
