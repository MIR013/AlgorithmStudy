import operator

def solution(genres, plays):
    answer = []
    

    genr={}#�帣:�� ���Ƚ��
    genr_list={}#�帣:[�뷡��ȣ,���Ƚ��] - ��� Ƚ�� ��, ��ȣ ���� ��
    n = len(plays)
    #�ʱ�ȭ

    for index in range(n):
        kinds = genres[index]
        if genr.get(kinds):
            genr[kinds] += plays[index]
            genr_list[kinds].append([index,plays[index]])
        else:
            genr[kinds] = plays[index]
            genr_list[kinds] = [[index,plays[index]]]
          
    #Ư�� �帣 ���ο��� ���Ƚ�� -> �뷡��ȣ ������ ����
    for g in genr_list.keys():
        #�����մϴ�. �ι�° ���ڴ� �������� ù���� ���ڴ� ��������
        genr_list[g] = sorted(genr_list[g],key=lambda x: (-x[1], +x[0]))
    
    #�帣�� �� �뷡 ���� ū �� ����
    genr = sorted(genr.items(), key=operator.itemgetter(1),reverse=True)
    
    for g in genr:
        #�տ��� �ΰ� ����(�Ѱ ������ ���� ����, �������� �ʴ� ���� �ƿ� �ȵ���)
        time = 0
        for data in genr_list[g[0]]:
            #print(data)
            if(time>=2):
                break
            answer.append(data[0])
            time += 1

        
    
    
    return answer