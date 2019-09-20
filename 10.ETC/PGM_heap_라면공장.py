import heapq

#�� �ð��ʰ��ΰ�? for���� break�Ȱɾ �׷���

def solution(stock, dates, supplies, k):
    answer = -1 #�� ùŸ�ӵ� ���ԵǼ�
    current_time = 0
    last_time = 0#������ �־��� ���� �ȳְ� ����Ʈ�� ���� ������ �ʱ� ����
    addition = []
    #�̷��� ���� �� ������ �����ϴ� ���� �ƴ϶�
    # �ϴ� �� ���� �� �Ŀ� �� ������ ������ �����ϴ°� �˰��� �� ������
    # ���丮�� �̷����� �� ���� �ȱ׷��� �Ǵϱ�!
    # �׷��� stoke�� 0���� ������ ��
    
    #�ʱ�ȭ ���ϸ� 1 time�� �� �ڵ� ¥�����
    heapq.heappush(addition,-stock)
    while current_time<k:# <=�� ���ԵǸ� ������ ���ε��� �� ������ �ް� ��
        #���� �����ô�!!
        for index,date in enumerate(dates): #������ ��������
            if(last_time < date <= current_time):#�������� �̹� ���� �� ������ �ȳְڴ�
                heapq.heappush(addition,-supplies[index])#���޷��� �־�� �̰� ū�Ŵ�� �޾ƿ� ��. max heap�̶� �ݴ�� ����
            if date > current_time: #���������̶�
                break

            
        #����ū�� �����ͼ� ����
        next_stock = -1 * heapq.heappop(addition)
        #��¥ �ѱ�� - �ƴ��� ���� ������ ��������� �Ϸ翡 �Ѱ��ϱ�
        last_time = current_time
        current_time += next_stock
        answer += 1
    
    return answer