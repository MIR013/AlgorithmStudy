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
        #��������
        if(isEmpty(truck_weights) and isEmpty(inBridgeWeight)):
            break
                
        #���⼭ �ð� ���̱� - ����ϴ°� ��� ���ư��� �Ѵ�
        newBridgeTime = []
        newBridgeWeight = []
        for t,w in zip(inBridgeTime,inBridgeWeight):
            t = t - 1
            if(t<=0):#�̹� �ٸ� ������ - ���� �����ֱ�
                nowWeight = nowWeight + w
            else:#�ٸ��� �������� ����
                newBridgeTime.append(t)
                newBridgeWeight.append(w)
            
        inBridgeWeight = newBridgeWeight
        inBridgeTime = newBridgeTime
                
       # print(answer,":",inBridgeWeight,":::",nowWeight)
        
        
        if(not isEmpty(truck_weights)):#Ż�� �ִ��� Ȯ��
            #�ٸ� ���� �ö� �� �ִ��� Ȯ��
            now = truck_weights.pop(0)#Ʈ�� ���Ը� �̴´�.

            if(nowWeight-now >= 0): #�ö� �� �ִ�.
                inBridgeWeight.append(now)
                inBridgeTime.append(bridge_length)
                nowWeight = nowWeight - now

            else: #�ö� �� ����.
                truck_weights.insert(0,now) #�ٽ� ����
            
        
        answer = answer + 1

        
        
                
    
    return answer