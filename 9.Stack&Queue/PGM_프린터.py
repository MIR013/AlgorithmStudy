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
        
    #큐 원래대로
    for data in new[::-1]:
        arr.insert(0,data)
    
    return result

def solution(priorities, location):
    answer = 0
    
    while location != -1:#찾고자하는 것의 위치가 -1일때까지
        if(isEmpty(priorities)):
            break
        
        now = priorities.pop(0)
        print('b',priorities)
        
        
        if(isHigh(now,priorities)):#만약에 나보다 우선순위가 높은게 있다면?!
            priorities.append(now) #뒤에 붙이고 location 변경
            print('a',priorities)
            if(location == 0):
                location = len(priorities) - 1
            else:
                location = location - 1
        else: #높은게 없다면 꺼낸다
            answer = answer + 1
            location = location - 1
                
            
        
    
    
    return answer