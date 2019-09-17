def isEmpty(arr):
    if(len(arr)==0):
        return True
    return False

def notDown(data,pri):
    time = 0
    
    #�̰� �� �����ؼ� �ϴ°� ���� - �� ��ġ�� ���صδ�
    arr = pri.copy()
    
    #�ϳ��� ���鼭 ���ϱ�
    for _ in range(len(arr)):
        newData = arr.pop(0)
        time = time + 1
        if(data>newData):#�ֽ��� ��������..
            break

    
    return time

def solveByQueue(prices):
    answer = []
    
    #�տ��� ���� �����ؾ��ϴ� queue���!
    for _ in range(len(prices)):
        data = prices.pop(0)
        answer.append(notDown(data,prices))
        
    return answer

def solveByFor(prices):
    answer = []
    
    for i in range(len(prices)):
        time = 0
        for j in range(i+1,len(prices)):
            time = time + 1
            if(prices[j]<prices[i]):
                break
            
        answer.append(time)
    
    return answer

def solution(prices):
    answer = []
    
    #������ �������� �������
    #�ϳ��� �ֽ��̶�� ����
    #1�ʿ� 1�̾��� �ֽ��� ���� [2,3,2,3]���� 1���Ϸ� �������� �ʾ����� 4��
    #2�ʿ� 2���� �ֽ��� [3,2,3]���� 2���Ϸ� �������� �ʾ����� 3��
    #3�ʿ� 3�̾��� �ֽ��� [2,3]���� 1�� �Ŀ� 2�� ���������� 1��
    #4�ʿ� 2���� �ֽ���[3]���� �������� �ʾ����� 1��
    #5�ʿ� 3�̾��� �ֽ��� �ð��� �� ������ �ʾ����� 0��
    
    #answer = solveByQueue(prices)
    answer = solveByFor(prices)
    
    
    return answer