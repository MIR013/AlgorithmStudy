def solution(n, lost, reserve):
    answer = 0
    
    #����Ʈ���� �����ϰ� �Ǹ� for������ �о���°� ������ �Ǿ �����Ǵ� lostģ������ ������ �ִ°� ���� �� ����.
    gotoGym = []
    
    #�ڱ��ڽ��� ����-�����̸� ���� Ȯ���ϰ� ���ƾ��� �ֳ��ϸ� �ռ��������� ���� ���� �����ϱ�
    for lost_person in lost:
        #�ڱ��ڽ�
        if(lost_person in reserve):
            gotoGym.append(lost_person)
            del(reserve[reserve.index(lost_person)])
    
    #�������� lost���� �������� - �ƴϸ� �� ã�´�
    lost = list(set(lost) - set(gotoGym))
    
    for lost_person in lost:

        #���ʺ��� ������
        if(lost_person-1 in reserve):
            gotoGym.append(lost_person)
            del(reserve[reserve.index(lost_person-1)])
        #������ ������ ������
        elif(lost_person+1 in reserve):
            gotoGym.append(lost_person)
            del(reserve[reserve.index(lost_person+1)])
    
    #������
    answer = n - len(set(lost) - set(gotoGym))
    
    return answer