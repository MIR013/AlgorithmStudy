def findNets(idx,stack,visited,length,computers):

    #종료조건 - 필요없을 듯
    
    visited[idx] = 1 #방문함
    
    
    #왜 여기서 0부터 해야 맞는 건가...?- 맞네 보장할 수 없네
    #이전꺼는 여기서는 볼 필요 없음 - 찾아봐야함
    for i in range(0,length):
        #방문한 적 없고 연결되어 있으면 들어가기
        if(visited[i] == 0 and computers[idx][i]==1):
            #stack.append(idx)
            findNets(i,stack,visited,length,computers)

    
    return

def solution(n, computers):
    answer = 0
    stack = []
    visited = []
    
    #초기화
    visited = [0 for i in range(n)]
    
    #BFS도 괜찮겠지만 깊이 탐색이니 DFS쓰는게 낫겠다.
    
    for idx in range(n):
        if(visited[idx]==0):
            findNets(idx,stack,visited,n,computers)
            #네트워크 개수 측정
            answer = answer + 1
            #전체 삭제
            #stack.clear()

    return answer