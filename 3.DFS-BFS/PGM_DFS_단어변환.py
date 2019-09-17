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
        #������ ã��!!
        global ans
        ans = result
        return
    
    for w,idx in zip(words,range(len(words))):
        #�ϳ��� �ٲ㵵 �Ǵ� �����̰� �湮�� ���� ���ٸ�
        if( not visited[idx] and isSameOne(start,w)):
            visited[idx] = 1
            result = result + 1
            DFSforWords(visited,w, target, words)
            #�ٽ� ���ƿ��� �ٸ��ſ��� ��ߵǴϱ�
            visited[idx] = 0 
            result = result - 1
            
    return

def solution(begin, target, words):
    answer = 0
    
    #dfs���� �ּҰ� ���ϱ��� ���������.
    #���η� ���鼭 �ּҰ��� ���Ϸ��� bfs�� ���� �� ���� ��
    #���� bfs�ϸ� �ּ� ���ϱ� �ָ�����
    
    #dfs�� ���� ���� ����ϰ� ���鼭 target�� ������ Ȯ���Ѵ�
    #��, �ּ��̱� ������ words�� �� �ѹ��� �湮�ؾ� �Ѵ�.
    
    visited = [0 for i in range(len(words))]
    DFSforWords(visited,begin, target, words)
    
    
    
    global ans
    answer = ans
    
    return answer