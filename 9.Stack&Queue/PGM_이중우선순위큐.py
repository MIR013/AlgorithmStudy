import heapq

def isEmpty(arr):
    if(len(arr)==0):
        return True
    return False

def solution(operations):
    answer = []
    pq = []
    
    #이게 이중인건가..
    
    for op in operations:
        data = op.split()
        if data[0] == "I":
            heapq.heappush(pq,int(data[1]))
        else:
            isMax = int(data[1])
            if(isEmpty(pq)):
                continue
            if(isMax == 1):#최대삭제
                pq.pop(pq.index(max(pq)))
            else:#최소삭제
                heapq.heappop(pq)
                
                
    if pq: #이렇게 바로 empty처리가 가능?!!
        answer.append(max(pq))
        answer.append(heapq.heappop(pq))
    else:
        answer = [0,0]
        
            
    
    return answer