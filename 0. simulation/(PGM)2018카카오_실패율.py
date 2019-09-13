import operator

def solution(N, stages):
    answer = []
    
    #��Ÿ�� ����: 0���� �����ų� �迭�ʰ��߰ų� ���
    #�ð��ʰ��� �ٸ���!�ڡڡڡڡڡڡڡ�
    
    #�ùķ��̼� ����
    #�ڷᱸ��: �������� ������ �� ��ųʸ�
    #          �������� �� �����ִ� ��� ���� ���ϴ� ��ųʸ�
    
    # 1. �������� �� ���� �ִ� ��� �� ���
    # 2. ���������� ������ �÷��̾� ��: stages[k]-1�ܰ�� ��� ����
    # 3. ���������� ���� ���ߴٸ� �������� 0
    # 4. ���� �������� �����ٸ� ���� �������� ����
    
    # ��ųʸ��� N���� ����+0���� �ʱ�ȭ
    stop_people={} 
    for num in range(1,N+2):
        stop_people[num]=0
    # �������� �� �����ϴ� �� ���ϱ�
    num_total = 0
    for s in stages:
        before_num = stop_people[s]
        stop_people[s] = before_num + 1
        num_total = num_total + 1
    
    # ������ ����ϱ� - 0���� ������ ��� ����
    fail_rate = {}
    for num in range(1,N+1): #���� n�������� ����
       # print(stop_people[num],"/",num_total)
        if(num_total == 0):
            fail_rate[num]=0
        else:
            fail_rate[num] = stop_people[num]/num_total
            num_total = num_total - stop_people[num]
        
    
    #������ ū ������ �迭�� ���� - �̰� ���� �˾Ƽ� �ε��� ���� ������ ����
    fail_rate = sorted(fail_rate.items(),key=operator.itemgetter(1),reverse=True)
    for data in fail_rate:
        answer.append(data[0])
        
    return answer