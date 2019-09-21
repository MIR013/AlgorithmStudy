def solution(n, edge):
    answer = 0

    #노드 당 1번에서 떨어진 거리를 저장
    distance = [0]*(n+1)
    visited = [0]*(n+1) #파이썬은 not in 이게 존재해서 인덱스로 01하는것보다 노드 번호 적어주는 게 좋을라나
                         # 속도상 문제가 생길거 같은데 1타임 접근이랑 not in이면 반복할텐데 내부에서
    
    #노드 수보다 간선 수가 많기 때문에 인접리스트 만드는게 더 빠르지 않을까? - for문보다 훨씬 빠름!!!
    #해봅시다 {노드번호:set([연결된 노드])} : 이렇게 만들면 차집합을 쓸 수 있어서 좋고, 의미상 한개만 올 수 있으니 for문에 조건을 안달아도 된다.
    vertex = {}
    for start, end in edge:
        if(vertex.get(start)):#노드가 하나라도 있으면
            vertex[start].add(end)
        else:
            vertex[start] = set([end])
        #반대 방향도 달아주자 - 왜냐 방향이 없응 간선이기 때문!!
        if(vertex.get(end)):
            vertex[end].add(start)
        else:
            vertex[end] = set([start])        
    
    
    #초기화
    queue = [1]
    distance[1] = 0
    visited[1] = 1
    
    #bfs
    while queue:
        daum = queue.pop(0)
        #연결된 새 노드 추가하기
        for data in vertex[daum]:
            if(not visited[data]):#방문한 데가 아니면 추가
                queue.append(data)
                distance[data] = distance[daum]+1
                visited[data] = 1
    
    #print(distance)
    answer = distance.count(max(distance))
    
    
    return answer