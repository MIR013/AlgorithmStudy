def isEmpty(arr):
    if(len(arr)==0):
        return True
    return False

def addSpeed(pro,spe):
    for index in range(0,len(pro)):
        pro[index] = pro[index] + spe[index]

def isDone(data,pro):
    #내꺼 이전까지 배열만 받아옵니더.. - 복사해서 사용하자.
    arr = pro.copy()
    
    for _ in range(0,len(arr)):
        if(isEmpty(arr)):
            break
        nextData = arr.pop()
        if(nextData<100):#내 앞이 100인가
            return False
    
    return True
    
def solution(progresses, speeds):
    answer = []
    
    while not isEmpty(progresses):
        #값을 먼저 올리고
        addSpeed(progresses, speeds)
        #100이상인 경우 체크를 합시다 - stack으로 뒤에서 부터
        for index in range(len(progresses)-1,-1,-1):
            data = progresses[index]
            if(data>=100):
                if(isDone(data,progresses[:index])):#index이전은 다 삭제!
                    progresses = progresses[index+1:]
                    speeds = speeds[index+1:]
                    answer.append(index+1)
                    break
                    
            
                
        
    
    return answer