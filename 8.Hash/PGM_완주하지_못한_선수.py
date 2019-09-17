def solution(participant, completion):
    participant.sort()
    completion.sort()
    findOne = False
    
    for p,c in zip(participant,completion):
        if(p!=c):
            answer=p
            findOne = True
            break;
    # 만약에 소팅해서 다 비교했는데 없었다면 맨 마지막이었던 애가 완주를 못한 것  
    if findOne == False:
        answer = participant[len(participant)-1]
    return answer
