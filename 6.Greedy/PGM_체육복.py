def solution(n, lost, reserve):
    answer = 0
    
    #리스트에서 삭제하게 되면 for문에서 읽어오는게 문제가 되어서 삭제되는 lost친구들을 저장해 주는게 좋을 것 같다.
    gotoGym = []
    
    #자기자신이 도난-여벌이면 먼저 확인하고 돌아야함 왜냐하면 앞서서빌려줘 버릴 수도 있으니까
    for lost_person in lost:
        #자기자신
        if(lost_person in reserve):
            gotoGym.append(lost_person)
            del(reserve[reserve.index(lost_person)])
    
    #들어가기전에 lost에서 지워야함 - 아니면 또 찾는당
    lost = list(set(lost) - set(gotoGym))
    
    for lost_person in lost:

        #왼쪽부터 빌리고
        if(lost_person-1 in reserve):
            gotoGym.append(lost_person)
            del(reserve[reserve.index(lost_person-1)])
        #없으면 오른쪽 빌리기
        elif(lost_person+1 in reserve):
            gotoGym.append(lost_person)
            del(reserve[reserve.index(lost_person+1)])
    
    #차집합
    answer = n - len(set(lost) - set(gotoGym))
    
    return answer