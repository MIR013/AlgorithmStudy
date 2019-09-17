def isEmpty(arr):
    if(len(arr)==0):
        return True
    return False

def addSpeed(pro,spe):
    for index in range(0,len(pro)):
        pro[index] = pro[index] + spe[index]

def isDone(data,pro):
    #���� �������� �迭�� �޾ƿɴϴ�.. - �����ؼ� �������.
    arr = pro.copy()
    
    for _ in range(0,len(arr)):
        if(isEmpty(arr)):
            break
        nextData = arr.pop()
        if(nextData<100):#�� ���� 100�ΰ�
            return False
    
    return True
    
def solution(progresses, speeds):
    answer = []
    
    while not isEmpty(progresses):
        #���� ���� �ø���
        addSpeed(progresses, speeds)
        #100�̻��� ��� üũ�� �սô� - stack���� �ڿ��� ����
        for index in range(len(progresses)-1,-1,-1):
            data = progresses[index]
            if(data>=100):
                if(isDone(data,progresses[:index])):#index������ �� ����!
                    progresses = progresses[index+1:]
                    speeds = speeds[index+1:]
                    answer.append(index+1)
                    break
                    
            
                
        
    
    return answer