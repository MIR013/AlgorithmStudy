

def solution(record):
    answer = []
    
    #�ܼ� �ùķ��̼�
    #1. Enter id nickname/ Leave id nickname/ Change id name�� ����� ����
    #   ������ �������� �Ľ� �� ���/���̵�/�г������� ���� ���� �� ó���ϸ� �� ��
    #2. ���� - �г��� �ߺ� ����/ �г����� �ٲ�� ��¹� ��� ����(->�������α׸� �ٲ�� �Ŷ� ������ �ʿ�����-> ��ųʸ� �ؼ� �����ϸ� ���� ��)
    #3. ���ڿ� �迭 ��ȯ - �α� ������ ���ܾ� �� ��
    
    personal_info = {}
    for info in record:
        data = info.split(' ')
        if data[0]=='Enter':
            personal_info[data[1]] = data[2] #�ִ� ���� ������� �˾Ƽ� ��
        elif data[0]=='Change':
             personal_info[data[1]] = data[2]
    
    #�α� �ۼ�
    for info in record:
        data = info.split(' ')
        if data[0]=='Enter':
            answer.append(personal_info[data[1]]+'���� ���Խ��ϴ�.')
        elif data[0]=='Leave':
            answer.append(personal_info[data[1]]+'���� �������ϴ�.')
            
    
    return answer