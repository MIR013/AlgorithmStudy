def solution(citations):
    answer = 0
    
    #�ִ� h�� ���ϴ°� ������... ���� ���ذ� �ȴ�
    citations.sort(reverse = True)
    
    #�ο�� ����ŭ �ߴ°� �ƴϹǷ� ��ü ���� �� ������
    for h in range(max(citations),-1,-1):
        value = 0 #h�� �̻� �ο�� ��
        for num in citations:
            if(num >= h):
                value = value + 1
        if(value >= h):
            answer = h
            break

        
    
    return answer