def findRed(row,col):
    return (row-2)*(col-2)

def findCases(number):
    result = []
    for col in range(number,0,-1):
        row = number/col
        if row.is_integer():#정수여야 곱해지는 수 가능
            row = int(row)
            if(col>=row and row>=3):#이러면 계산 가능
                result.append([col,row])
    return result

def solution(brown, red):
    answer = []
    values = findCases(brown+red)
    for data in values:
        if(findRed(data[1],data[0]) == red):
            answer = data
            break
    
    return answer