import itertools
import math
    
def isPrim(num):
    if(num<=1):
        return False
    if(num == 2):
        return True
    for i in range(2,int(math.sqrt(num)+1)):
        if(num%i == 0):
            return False
    return True

def byPermutation(numbers):
    result = []
    length = len(numbers)
    
    #자리수부터 처리
    for number in range(1,length+1):
        #자리수 당 순열 계산
        for order in itertools.permutations([i for i in range(length)],number):
            #선택된 종이끼리 합쳐서 수 만들기
            data = ""
            for index in order:
                data = data + numbers[index]
                
            #같은 수 처리!
            data = int(data)
            if(data not in result):            
                if(isPrim(data)):
                    result.append(data)
        
    return len(result)

def solution(numbers):
    answer = 0
    #순열이다
    answer = byPermutation(numbers)
    return answer