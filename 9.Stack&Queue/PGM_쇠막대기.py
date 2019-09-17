def solution(arrangement):
    answer = 0
    #앞에 입력 조건은 거의 의미가 없음
    #중요한 건 레이저를 기준으로 레이저가 몇개의 막대기를 자를 수 있는가가 중요
    
    raser = []
    time = 0
    before = ""
    #이전이 '('여야 ')'가 막대기가 됨
    
    for t in arrangement:
        if(t == ")"):
            raser.pop()
            if before == "(":    
                time = time + len(raser)
            else:
                time = time + 1
            before = ")"
        else:
            raser.append(t)
            before = "("
            
        #print(raser,"time: ",time)
    
    answer = time
    return answer