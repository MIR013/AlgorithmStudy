def solution(arrangement):
    answer = 0
    #�տ� �Է� ������ ���� �ǹ̰� ����
    #�߿��� �� �������� �������� �������� ��� ����⸦ �ڸ� �� �ִ°��� �߿�
    
    raser = []
    time = 0
    before = ""
    #������ '('���� ')'�� ����Ⱑ ��
    
    for t in arrangement:
        if(t == ")"):
            raser.pop()
            if before == "(":    
                time = time + len(raser)
            else:
                time = time + 1
            before = ")"
        else:
            raser.append(t)
            before = "("
            
        #print(raser,"time: ",time)
    
    answer = time
    return answer