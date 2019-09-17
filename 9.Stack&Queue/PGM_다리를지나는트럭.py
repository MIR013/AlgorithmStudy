def isEmpty(arr):
    if(len(arr)==0):
        return True
    return False

def solution(bridge_length, weight, truck_weights):
    answer = 0
    inBridgeWeight=[]
    inBridgeTime=[]
    nowWeight=weight
    
    while True:
        #종료조건
        if(isEmpty(truck_weights) and isEmpty(inBridgeWeight)):
            break
                
        #여기서 시간 줄이기 - 대기하는게 없어도 돌아가야 한다
        newBridgeTime = []
        newBridgeWeight = []
        for t,w in zip(inBridgeTime,inBridgeWeight):
            t = t - 1
            if(t<=0):#이미 다리 지나감 - 무게 더해주기
                nowWeight = nowWeight + w
            else:#다리를 지나가지 않음
                newBridgeTime.append(t)
                newBridgeWeight.append(w)
            
        inBridgeWeight = newBridgeWeight
        inBridgeTime = newBridgeTime
                
       # print(answer,":",inBridgeWeight,":::",nowWeight)
        
        
        if(not isEmpty(truck_weights)):#탈게 있는지 확인
            #다리 위에 올라갈 수 있는지 확인
            now = truck_weights.pop(0)#트럭 무게를 뽑는다.

            if(nowWeight-now >= 0): #올라갈 수 있다.
                inBridgeWeight.append(now)
                inBridgeTime.append(bridge_length)
                nowWeight = nowWeight - now

            else: #올라갈 수 없다.
                truck_weights.insert(0,now) #다시 넣음
            
        
        answer = answer + 1

        
        
                
    
    return answer