def addStack(stack, value, start, digit,length,count):
    nextStart = 0
    while True:
        #stack이 비어있으면 바로 넣으셈
        if not stack:
            stack.append(value)
            break
        #안비어 있으면 작은게 있으면 버리고 큰게 들어갈 수 있을때까지
        else:
            #length의 -k 부터는 pop하면 안됨 그냥 넣어야함
            if(len(stack)+length-count == digit):
                stack.append(value)
                break

            before = stack.pop()
            if(before>=value):#작으면 아예 빼야함
                stack.append(before)
                stack.append(value)
                break
            #크면 한번 더 돌것지
            else:
                nextStart += 1 #뺀거의 개수를 세줌

    return nextStart

def solution(number, k):
    answer = ''
    
    '''
    너무 이상하게 풀었는데 다음에 다시 풀자
    
    '''
    
    length = len(number)
    digit = length - k
    stack = []

    start = 0
    count = 0
    while count<length:
        value = int(number[count])
        #이건 한개씩 넣어주는 것임
        nextStart = addStack(stack, value, start, digit,length,count)
        start += nextStart#가장 앞의 인덱스를 기억
        count += 1

    answer = "".join(list(map(str,stack[:digit])))

    return answer