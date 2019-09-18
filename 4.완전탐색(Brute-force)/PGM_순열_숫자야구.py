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
    #��� �����ؼ� �˻��ϴ°� ���� ��
    #original���� ball���� �ֵ鸸 ��ȯ
    for comp in original:
        ball_num = 0
        for index in range(3):
            if(comp[index] in num and comp[index]!=num[index]):
                #�������� ���� �ڸ��� �ƴϸ� true
                ball_num += 1
        
        if(ball_num == ball):
            result.append(comp)
         
    return result

def Strike(num,strike,original):
    result = []
    #���⵵ original�� num�� ���Ͽ� ��� strike���� Ȯ��
    if(strike == 3):
        return [num]
        
    for comp in original:
        strike_num = 0
        for index in range(3):
            if(comp[index] in num and comp[index]==num[index]):
                #���ϰ� �����ڸ��� true
                strike_num += 1
        
        if(strike_num == strike):
            result.append(comp) 
        
    return result

def solution(baseball):
    answer = 0
    original = []
    #original�ʱ�ȭ  - ���� �� �ߺ� �Ұ� (����)          
    for order in itertools.permutations([i for i in range(1,10)],3):
        #original.append("".join(list(map(str,list(order)))))
        original.append(list(order))
    
    for data in baseball:#����� ������ �ϳ��ϳ� Ȯ���ϸ� �����ϱ�!
        num = maketoList(data[0])
        original = Strike(num,data[1],original)
        original = Ball(num,data[2],original)
    answer = len(original)
    
    return answer