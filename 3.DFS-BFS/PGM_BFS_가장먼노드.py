def solution(n, edge):
    answer = 0

    #��� �� 1������ ������ �Ÿ��� ����
    distance = [0]*(n+1)
    visited = [0]*(n+1) #���̽��� not in �̰� �����ؼ� �ε����� 01�ϴ°ͺ��� ��� ��ȣ �����ִ� �� ������
                         # �ӵ��� ������ ����� ������ 1Ÿ�� �����̶� not in�̸� �ݺ����ٵ� ���ο���
    
    #��� ������ ���� ���� ���� ������ ��������Ʈ ����°� �� ������ ������? - for������ �ξ� ����!!!
    #�غ��ô� {����ȣ:set([����� ���])} : �̷��� ����� �������� �� �� �־ ����, �ǹ̻� �Ѱ��� �� �� ������ for���� ������ �ȴ޾Ƶ� �ȴ�.
    vertex = {}
    for start, end in edge:
        if(vertex.get(start)):#��尡 �ϳ��� ������
            vertex[start].add(end)
        else:
            vertex[start] = set([end])
        #�ݴ� ���⵵ �޾����� - �ֳ� ������ ���� �����̱� ����!!
        if(vertex.get(end)):
            vertex[end].add(start)
        else:
            vertex[end] = set([start])        
    
    
    #�ʱ�ȭ
    queue = [1]
    distance[1] = 0
    visited[1] = 1
    
    #bfs
    while queue:
        daum = queue.pop(0)
        #����� �� ��� �߰��ϱ�
        for data in vertex[daum]:
            if(not visited[data]):#�湮�� ���� �ƴϸ� �߰�
                queue.append(data)
                distance[data] = distance[daum]+1
                visited[data] = 1
    
    #print(distance)
    answer = distance.count(max(distance))
    
    
    return answer