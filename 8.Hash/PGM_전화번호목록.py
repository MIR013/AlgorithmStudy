def byFor(phone_book):
    
    phone_book.sort()#�տ� ª���� ���� �� ���ص� ��
    
    #str�� ���ԵǾ��ִ��� Ȯ���ϴ� �Լ� string.startswith(����)
    length = len(phone_book)
    for i in range(0,length):
        for j in range(i+1,length):
            if(phone_book[j].startswith(phone_book[i])):
                #�� ���ϸ� �ȴ�
                return False
    return True

def solution(phone_book):
    answer = True
    
    #str�� ���ԵǾ��ִ��� Ȯ���ϴ� �Լ� string.startswith(����)
    answer = byFor(phone_book)
    
    #hash..�ǹ� �ִ°� 
    #for���Ҷ� �ʹ� �����ɸ��� hash�� �ٲٰ� �ƴϸ� for���°�..
    
    
    return answer