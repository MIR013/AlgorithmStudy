def isEmpty(arr):
    if(len(arr)==0):
        return True
    return False

def isHigh(now,arr):
    new = []
    result = False
    
    for _ in range(0,len(arr)):
        if(isEmpty(arr)):
            result = False    
            break
            
        nextData = arr.pop(0)
        new.append(nextData)
        
        if(now < nextData):
            result = True
            break
        
    #ť �������
    for data in new[::-1]:
        arr.insert(0,data)
    
    return result

def solution(priorities, location):
    answer = 0
    
    while location != -1:#ã�����ϴ� ���� ��ġ�� -1�϶�����
        if(isEmpty(priorities)):
            break
        
        now = priorities.pop(0)
        print('b',priorities)
        
        
        if(isHigh(now,priorities)):#���࿡ ������ �켱������ ������ �ִٸ�?!
            priorities.append(now) #�ڿ� ���̰� location ����
            print('a',priorities)
            if(location == 0):
                location = len(priorities) - 1
            else:
                location = location - 1
        else: #������ ���ٸ� ������
            answer = answer + 1
            location = location - 1
                
            
        
    
    
    return answer