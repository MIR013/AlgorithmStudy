def solution(people, limit):
    answer = 0
    
    #"����Ʈ�� �ִ��� ���� ����Ͽ�" -> �׸���
    #�׷����� �ִ��� limit�� ������ ��� �Ѵ�.,
    #n^2�� 2500000000 �� ���ϸ� ���ư����� - �ȵ�
    #�ִ��� o(n)���� ��������
    
    #ū ���� �������� �����ϰ� ���� Ż ģ���� ���� �����ָ� ����.
    #���� ���� ���� �ְ� �ȵǸ� �� ȥ�� Ÿ���Ѵ�.
    
    people = sorted(people,reverse = True)
    light = 0
    heavy = len(people)-1
    while people:
        #����
        if(light > heavy):
            break
        
        #���� Ż ģ�� Ȯ��
        if(people[light] + people[heavy] <= limit):
            #���� ź��
            heavy -= 1
        light += 1
        answer += 1
        
    return answer