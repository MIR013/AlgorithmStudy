def solution(people, limit):
    answer = 0
    
    #"구명보트를 최대한 적게 사용하여" -> 그리디
    #그러려면 최대한 limit에 가깝게 줘야 한다.,
    #n^2은 2500000000 음 잘하면 돌아갈랑가 - 안됨
    #최대한 o(n)으로 만들어야함
    
    #큰 값을 기준으로 선택하고 같이 탈 친구는 제일 작은애를 본다.
    #만약 제일 작은 애가 안되면 걍 혼자 타야한다.
    
    people = sorted(people,reverse = True)
    light = 0
    heavy = len(people)-1
    while people:
        #종료
        if(light > heavy):
            break
        
        #같이 탈 친구 확인
        if(people[light] + people[heavy] <= limit):
            #둘이 탄다
            heavy -= 1
        light += 1
        answer += 1
        
    return answer