def solution(citations):
    answer = 0
    
    #최대 h를 구하는거 같은데... 문제 이해가 안댐
    citations.sort(reverse = True)
    
    #인용된 수만큼 뜨는게 아니므로 전체 수를 다 봐야함
    for h in range(max(citations),-1,-1):
        value = 0 #h번 이상 인용된 논문
        for num in citations:
            if(num >= h):
                value = value + 1
        if(value >= h):
            answer = h
            break

        
    
    return answer