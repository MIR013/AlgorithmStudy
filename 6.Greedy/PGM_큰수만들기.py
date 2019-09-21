def addStack(stack, value, start, digit,length,count):
    nextStart = 0
    while True:
        #stack�� ��������� �ٷ� ������
        if not stack:
            stack.append(value)
            break
        #�Ⱥ�� ������ ������ ������ ������ ū�� �� �� ����������
        else:
            #length�� -k ���ʹ� pop�ϸ� �ȵ� �׳� �־����
            if(len(stack)+length-count == digit):
                stack.append(value)
                break

            before = stack.pop()
            if(before>=value):#������ �ƿ� ������
                stack.append(before)
                stack.append(value)
                break
            #ũ�� �ѹ� �� ������
            else:
                nextStart += 1 #������ ������ ����

    return nextStart

def solution(number, k):
    answer = ''
    
    '''
    �ʹ� �̻��ϰ� Ǯ���µ� ������ �ٽ� Ǯ��
    
    '''
    
    length = len(number)
    digit = length - k
    stack = []

    start = 0
    count = 0
    while count<length:
        value = int(number[count])
        #�̰� �Ѱ��� �־��ִ� ����
        nextStart = addStack(stack, value, start, digit,length,count)
        start += nextStart#���� ���� �ε����� ���
        count += 1

    answer = "".join(list(map(str,stack[:digit])))

    return answer