import itertools

def maketoList(num):
    div = 100
    result = []    
    
    for _ in range(3):
        result.append((int(num//div)))
        num %= div
        div /= 10
    return result

def Ball(num,ball,original):
    result = []
    #얘는 복잡해서 검사하는게 나을 듯
    #original에서 ball볼인 애들만 반환
    for comp in original:
        ball_num = 0
        for index in range(3):
            if(comp[index] in num and comp[index]!=num[index]):
                #속하지만 같은 자리가 아니면 true
                ball_num += 1
        
        if(ball_num == ball):
            result.append(comp)
         
    return result

def Strike(num,strike,original):
    result = []
    #여기도 original과 num을 비교하여 몇개의 strike인지 확인
    if(strike == 3):
        return [num]
        
    for comp in original:
        strike_num = 0
        for index in range(3):
            if(comp[index] in num and comp[index]==num[index]):
                #속하고 같은자리면 true
                strike_num += 1
        
        if(strike_num == strike):
            result.append(comp) 
        
    return result

def solution(baseball):
    answer = 0
    original = []
    #original초기화  - 같은 수 중복 불가 (순열)          
    for order in itertools.permutations([i for i in range(1,10)],3):
        #original.append("".join(list(map(str,list(order)))))
        original.append(list(order))
    
    for data in baseball:#경우의 수에서 하나하나 확인하며 제거하기!
        num = maketoList(data[0])
        original = Strike(num,data[1],original)
        original = Ball(num,data[2],original)
    answer = len(original)
    
    return answer