import heapq

def isEmpty(arr):
    if(len(arr)==0):
        return True
    return False

def solution(scoville, K):
    answer = 0
    heap = []
    
    
    for data in scoville:
        heapq.heappush(heap,data)
    
    
    while True:
        #가장 작은 값의 여부를 확인
        if(isEmpty(heap)):
            break
        smallData = heapq.heappop(heap)
        
        if smallData>=K:
            break
        
        #다음값을 뽑아 처리
        if(isEmpty(heap)):
            answer = -1 #배열이 하나만 남았다는 뜻은 만들 수 없다는 뜻이다.
            break
        nextSmallData = heapq.heappop(heap)
        nextScoville = smallData + (nextSmallData*2)
        
        #추가
        heapq.heappush(heap,nextScoville)
        answer = answer + 1
    
    
    return answer