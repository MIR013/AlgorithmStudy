def findNets(idx,stack,visited,length,computers):

    #�������� - �ʿ���� ��
    
    visited[idx] = 1 #�湮��
    
    
    #�� ���⼭ 0���� �ؾ� �´� �ǰ�...?- �³� ������ �� ����
    #�������� ���⼭�� �� �ʿ� ���� - ã�ƺ�����
    for i in range(0,length):
        #�湮�� �� ���� ����Ǿ� ������ ����
        if(visited[i] == 0 and computers[idx][i]==1):
            #stack.append(idx)
            findNets(i,stack,visited,length,computers)

    
    return

def solution(n, computers):
    answer = 0
    stack = []
    visited = []
    
    #�ʱ�ȭ
    visited = [0 for i in range(n)]
    
    #BFS�� ���������� ���� Ž���̴� DFS���°� ���ڴ�.
    
    for idx in range(n):
        if(visited[idx]==0):
            findNets(idx,stack,visited,n,computers)
            #��Ʈ��ũ ���� ����
            answer = answer + 1
            #��ü ����
            #stack.clear()

    return answer