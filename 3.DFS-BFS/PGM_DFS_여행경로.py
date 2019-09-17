from operator import itemgetter

suceess = False

def DFSforRoute(stack,start,visited,tickets):
    

    #들어온 애는 비행기표 사용했단 뜻이므로 넣는다(반드시 먼저 넣어야함 방문한 곳이니까)
    stack.append(start)
    
    #★★★★★★★★★★★★★★★★★★★★★
    #경로가 다이어져 있었는지 확인해야한다.
    #1->2,1->3,3->1의 경우 1->2에서 끝난다고 한다
    global suceess
    if(len(stack) == len(tickets)+1):
        suceess = True
        return
        
    #사용할 수 있는 티켓 검사
    #갈 수 있는길이 여러개라도 차피 끝이 있기 때문에 사이클 안생김
    for ticket,idx in zip(tickets,range(len(tickets))):
        if(not visited[idx] and start == ticket[0]): #사용한 적 없고, 티켓의 출발지와 같을 경우
            visited[idx] = 1
            DFSforRoute(stack,ticket[1],visited,tickets)
            if(suceess == False):
                #다 돈게 아닌데 끝나버린 경우 다시 돌게 한다.
                visited[idx] = 0
                stack.pop()
    
    return


def solution(tickets):
    answer = []
    stack = []
    
    #tickets = [["ICN","ABC"],["ICN","QWE"],["QWE","ICN"]]
    
    visited = [0 for i in range(len(tickets))]
    
    #중복있으면 알파벳 순!!이라서 티켓의 도착지를 알파벳 순으로 소팅해두면...?
    tickets.sort(key = itemgetter(1))
    
    DFSforRoute(stack,"ICN",visited,tickets)
    answer = stack
   
    return answer