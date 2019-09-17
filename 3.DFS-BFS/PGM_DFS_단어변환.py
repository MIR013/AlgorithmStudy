result = 0
ans = 0
def isSameOne(source,target):
    
    diff = 0
    for i in range(len(source)):
        if(source[i]!=target[i]):
            diff = diff + 1
            
    if(diff == 1):
        return True
    else:   
        return False

def DFSforWords(visited,start, target, words):
    
    global result
    
    if(start == target):
        #같은거 찾음!!
        global ans
        ans = result
        return
    
    for w,idx in zip(words,range(len(words))):
        #하나만 바꿔도 되는 문자이고 방문한 적이 없다면
        if( not visited[idx] and isSameOne(start,w)):
            visited[idx] = 1
            result = result + 1
            DFSforWords(visited,w, target, words)
            #다시 돌아오면 다른거에서 써야되니까
            visited[idx] = 0 
            result = result - 1
            
    return

def solution(begin, target, words):
    answer = 0
    
    #dfs쓰면 최소값 구하기하 힘들어진다.
    #내부로 들어가면서 최소값을 구하려면 bfs를 쓰는 게 나을 듯
    #않이 bfs하면 최소 구하기 애매해짐
    
    #dfs를 통해 가장 깊숙하게 들어가면서 target과 같은디 확인한다
    #단, 최소이기 때문에 words는 단 한번만 방문해야 한다.
    
    visited = [0 for i in range(len(words))]
    DFSforWords(visited,begin, target, words)
    
    
    
    global ans
    answer = ans
    
    return answer