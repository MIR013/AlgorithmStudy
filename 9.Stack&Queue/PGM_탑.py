def isEmpty(heights):
    if(len(heights) == 0):
        return True
    return False
    
def getRecentNum(now, heights):
    saveStack = []
    result = 0
    
    for index in range(len(heights)-1,-1,-1):
        #빈 값인지 확인하기
        if(isEmpty(heights)):
            result = 0
            break
            
        nextData = heights.pop()
        saveStack.append(nextData)

        #나보다 큰 값 찾기
        if(nextData>now):
            result = index+1
            break
    
    #값다시 push해 주기
    for data in saveStack[::-1]:
        heights.append(data)
    
    return result
    
def solution(heights):
    answer = []
    
    #그냥 반복하는 것(2중 for문)과 stack의 차이점이 뭘까?
    #   - 시간 상 오래걸리는갑네
    #   - O(n^2) vs O(n * for문보다 덜 찾음 k)
    
    #왼쪽이면 stack, 오른쪽이면 queue일듯
    for i in range(0,len(heights)):
        now = heights.pop()
        answer.append(getRecentNum(now,heights))
   
    return answer[::-1]