def isEmpty(heights):
    if(len(heights) == 0):
        return True
    return False
    
def getRecentNum(now, heights):
    saveStack = []
    result = 0
    
    for index in range(len(heights)-1,-1,-1):
        #�� ������ Ȯ���ϱ�
        if(isEmpty(heights)):
            result = 0
            break
            
        nextData = heights.pop()
        saveStack.append(nextData)

        #������ ū �� ã��
        if(nextData>now):
            result = index+1
            break
    
    #���ٽ� push�� �ֱ�
    for data in saveStack[::-1]:
        heights.append(data)
    
    return result
    
def solution(heights):
    answer = []
    
    #�׳� �ݺ��ϴ� ��(2�� for��)�� stack�� �������� ����?
    #   - �ð� �� �����ɸ��°���
    #   - O(n^2) vs O(n * for������ �� ã�� k)
    
    #�����̸� stack, �������̸� queue�ϵ�
    for i in range(0,len(heights)):
        now = heights.pop()
        answer.append(getRecentNum(now,heights))
   
    return answer[::-1]