import operator

def simplefind(dstree,index):
    root = index
    while dstree[root]>=0:
        root = dstree[root]
    return root

def weightedUnion(dstree,i,j):
    temp = dstree[i] + dstree[j]
    if dstree[i] > dstree[j]:
        dstree[i] = j
        dstree[j] = temp
    else:
        dstree[j] = i
        dstree[i] = temp
    
def solution(n, costs):
    answer = 0
    
    '''
    전형적인 kruskal
    '''
    dstree = [-1]*n
    count = 0
    costs = sorted(costs,key = operator.itemgetter(2))
    for i,j,cost in costs:
        iroot = simplefind(dstree,i)
        jroot = simplefind(dstree,j)
        if(iroot != jroot):
            weightedUnion(dstree,iroot,jroot)
            count += 1
            answer += cost
        if count == n-1:
            break
    
    return answer