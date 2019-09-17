import heapq

def isEmpty(arr):
    if(len(arr)==0):
        return True
    return False

def solution(operations):
    answer = []
    pq = []
    
    #�̰� �����ΰǰ�..
    
    for op in operations:
        data = op.split()
        if data[0] == "I":
            heapq.heappush(pq,int(data[1]))
        else:
            isMax = int(data[1])
            if(isEmpty(pq)):
                continue
            if(isMax == 1):#�ִ����
                pq.pop(pq.index(max(pq)))
            else:#�ּһ���
                heapq.heappop(pq)
                
                
    if pq: #�̷��� �ٷ� emptyó���� ����?!!
        answer.append(max(pq))
        answer.append(heapq.heappop(pq))
    else:
        answer = [0,0]
        
            
    
    return answer