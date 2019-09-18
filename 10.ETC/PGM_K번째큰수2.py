def findKvalue(arr,k):
    #list.sort() - 리스트의 값을 바꿈
    #sorted(list) - 리스트의 값이 안바뀌고 반환함
    
    return sorted(arr)[k]

def solution(array, commands):
    answer = []
    
    #파이썬은 모두 포인터라 값 바뀌는 것 조심
    for cmd in commands:
        answer.append(findKvalue(array[cmd[0]-1:cmd[1]],cmd[2]-1))
    
    return answer