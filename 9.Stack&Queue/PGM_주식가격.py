def isEmpty(arr):
    if(len(arr)==0):
        return True
    return False

def notDown(data,pri):
    time = 0
    
    #이거 걍 복사해서 하는게 편함 - 값 합치기 안해두댐
    arr = pri.copy()
    
    #하나씩 빼면서 비교하긔
    for _ in range(len(arr)):
        newData = arr.pop(0)
        time = time + 1
        if(data>newData):#주식이 내려갓다..
            break

    
    return time

def solveByQueue(prices):
    answer = []
    
    #앞에서 부터 접근해야하니 queue사용!
    for _ in range(len(prices)):
        data = prices.pop(0)
        answer.append(notDown(data,prices))
        
    return answer

def solveByFor(prices):
    answer = []
    
    for i in range(len(prices)):
        time = 0
        for j in range(i+1,len(prices)):
            time = time + 1
            if(prices[j]<prices[i]):
                break
            
        answer.append(time)
    
    return answer

def solution(prices):
    answer = []
    
    #문제를 거지같이 만들었네
    #하나의 주식이라고 생각
    #1초에 1이었던 주식이 뒤의 [2,3,2,3]동안 1이하로 떨어지지 않았으니 4초
    #2초에 2였던 주식이 [3,2,3]동안 2이하로 떨어지지 않았으니 3초
    #3초에 3이었던 주식이 [2,3]동안 1초 후에 2로 떨어졌으니 1초
    #4초에 2였건 주식이[3]동안 떨어지지 않았으니 1초
    #5초에 3이었던 주식이 시간이 더 지나지 않았으니 0초
    
    #answer = solveByQueue(prices)
    answer = solveByFor(prices)
    
    
    return answer