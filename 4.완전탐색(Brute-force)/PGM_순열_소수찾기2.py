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
    
    #�ڸ������� ó��
    for number in range(1,length+1):
        #�ڸ��� �� ���� ���
        for order in itertools.permutations([i for i in range(length)],number):
            #���õ� ���̳��� ���ļ� �� �����
            data = ""
            for index in order:
                data = data + numbers[index]
                
            #���� �� ó��!
            data = int(data)
            if(data not in result):            
                if(isPrim(data)):
                    result.append(data)
        
    return len(result)

def solution(numbers):
    answer = 0
    #�����̴�
    answer = byPermutation(numbers)
    return answer