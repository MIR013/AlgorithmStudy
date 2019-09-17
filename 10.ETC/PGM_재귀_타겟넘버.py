total = 0

def calArr(numbers,types):
    result = 0
    for value, sign in zip(numbers,types):
        if sign == 0:#+
            result = result + value
        else:#-
            result = result - value
            
    return result
    

def choicePM(idx,num,arr,length,numbers,target):
    if(idx>=length):
        #print(arr)
        global total
        
        if(calArr(numbers,arr) == target):
            total = total + 1    
        return
    
    arr[idx] = 0
    choicePM(idx+1,0,arr,length,numbers,target)
    arr[idx] = 1
    choicePM(idx+1,1,arr,length,numbers,target)
    
    return
    
def solution(numbers, target):
    answer = 0
    types = []
    global total
    
    for _ in range(len(numbers)):
        types.append(-1)
    
    choicePM(0,-1,types,len(types),numbers,target)
    answer = total
    return answer