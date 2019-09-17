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
        #���� ���� ���� ���θ� Ȯ��
        if(isEmpty(heap)):
            break
        smallData = heapq.heappop(heap)
        
        if smallData>=K:
            break
        
        #�������� �̾� ó��
        if(isEmpty(heap)):
            answer = -1 #�迭�� �ϳ��� ���Ҵٴ� ���� ���� �� ���ٴ� ���̴�.
            break
        nextSmallData = heapq.heappop(heap)
        nextScoville = smallData + (nextSmallData*2)
        
        #�߰�
        heapq.heappush(heap,nextScoville)
        answer = answer + 1
    
    
    return answer