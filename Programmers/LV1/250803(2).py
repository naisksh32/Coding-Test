def solution(bandage, health, attacks):
    # 전체 시간 결정
    tot_time = attacks[-1][0]
    # 최대체력, 현재체력 변수 설정
    max_health = health
    pre_health = health
    # 회복 연속성공 보너스 변수 설정
    bonus = 0
    # 공격시간 설정
    attack_time = [row[0] for row in attacks]
    attack_nums = 0
    
    # 1초 시간이 경과할 때 마다 상황 분석
    for i in range(0, tot_time+1):
        # 현재 상태
        print(f"{i}초 상태")
        
        # 공격 시간대가 되면 활성화
        if i in attack_time:
            print('공격 받음')
            print(attacks[attack_nums][1])
            pre_health -= attacks[attack_nums][1]
            attack_nums += 1
            bonus = 0
            
        # 공격 시간대가 아니면 회복
        else:
            print('회복 중')
            # 1초당 회복량에 비례한 체력 회복
            pre_health += bandage[1]
            bonus += 1
            # 연속 회복 성공 시 추가 회복
            if bonus == bandage[0]:
                pre_health += bandage[2]
                bonus = 0
            # 만약 최대치를 넘어가면 최대치만큼 회복
            if pre_health > max_health:
                pre_health = max_health

        print(f'현재체력: {pre_health}')
        print()
        
        # 사망처리 로직
        if pre_health <= 0:
            return -1
        
    answer = pre_health
    return answer