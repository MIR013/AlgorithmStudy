from operator import itemgetter

suceess = False

def DFSforRoute(stack,start,visited,tickets):
    

    #���� �ִ� �����ǥ ����ߴ� ���̹Ƿ� �ִ´�(�ݵ�� ���� �־���� �湮�� ���̴ϱ�)
    stack.append(start)
    
    #�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
    #��ΰ� ���̾��� �־����� Ȯ���ؾ��Ѵ�.
    #1->2,1->3,3->1�� ��� 1->2���� �����ٰ� �Ѵ�
    global suceess
    if(len(stack) == len(tickets)+1):
        suceess = True
        return
        
    #����� �� �ִ� Ƽ�� �˻�
    #�� �� �ִ±��� �������� ���� ���� �ֱ� ������ ����Ŭ �Ȼ���
    for ticket,idx in zip(tickets,range(len(tickets))):
        if(not visited[idx] and start == ticket[0]): #����� �� ����, Ƽ���� ������� ���� ���
            visited[idx] = 1
            DFSforRoute(stack,ticket[1],visited,tickets)
            if(suceess == False):
                #�� ���� �ƴѵ� �������� ��� �ٽ� ���� �Ѵ�.
                visited[idx] = 0
                stack.pop()
    
    return


def solution(tickets):
    answer = []
    stack = []
    
    #tickets = [["ICN","ABC"],["ICN","QWE"],["QWE","ICN"]]
    
    visited = [0 for i in range(len(tickets))]
    
    #�ߺ������� ���ĺ� ��!!�̶� Ƽ���� �������� ���ĺ� ������ �����صθ�...?
    tickets.sort(key = itemgetter(1))
    
    DFSforRoute(stack,"ICN",visited,tickets)
    answer = stack
   
    return answer