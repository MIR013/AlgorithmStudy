def findKvalue(arr,k):
    #list.sort() - ����Ʈ�� ���� �ٲ�
    #sorted(list) - ����Ʈ�� ���� �ȹٲ�� ��ȯ��
    
    return sorted(arr)[k]

def solution(array, commands):
    answer = []
    
    #���̽��� ��� �����Ͷ� �� �ٲ�� �� ����
    for cmd in commands:
        answer.append(findKvalue(array[cmd[0]-1:cmd[1]],cmd[2]-1))
    
    return answer