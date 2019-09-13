import operator

def solution(N, stages):
    answer = []
    
    #런타임 에러: 0으로 나눴거나 배열초과했거나 등등
    #시간초과와 다르다!★★★★★★★★
    
    #시뮬레이션 문제
    #자료구조: 스테이지 실패율 용 딕셔너리
    #          스테이지 별 멈춰있는 사람 수를 정하는 딕셔너리
    
    # 1. 스테이지 별 멈춰 있는 사람 수 계산
    # 2. 스테이지에 도달한 플레이어 수: stages[k]-1단계는 모두 포함
    # 3. 스테이지에 도달 못했다면 실패율은 0
    # 4. 같은 실패율을 가진다면 작은 스테이지 부터
    
    # 딕셔너리를 N까지 정의+0으로 초기화
    stop_people={} 
    for num in range(1,N+2):
        stop_people[num]=0
    # 스테이지 당 도달하는 수 구하기
    num_total = 0
    for s in stages:
        before_num = stop_people[s]
        stop_people[s] = before_num + 1
        num_total = num_total + 1
    
    # 실패율 계산하기 - 0으로 나누는 경우 주의
    fail_rate = {}
    for num in range(1,N+1): #여기 n차까지만 존재
       # print(stop_people[num],"/",num_total)
        if(num_total == 0):
            fail_rate[num]=0
        else:
            fail_rate[num] = stop_people[num]/num_total
            num_total = num_total - stop_people[num]
        
    
    #실패율 큰 순서로 배열에 저장 - 이거 쓰면 알아서 인덱스 작은 순으로 나옴
    fail_rate = sorted(fail_rate.items(),key=operator.itemgetter(1),reverse=True)
    for data in fail_rate:
        answer.append(data[0])
        
    return answer