def solution(clothes):
    answer = 0
    
    #�� ������ ���� �ؽ�(��ųʸ�) ����
    typeClothes={}
    for data in clothes:
        if(typeClothes.get(data[1])):
            typeClothes.get(data[1]).append(data[0])
        else:
            typeClothes[data[1]] = [data[0]]
    
    #���� �� �ִ� ��Ʈ �����
    #�ڱⰡ �ȳ��� Ȯ�������ؼ� �渮 +1 ���� ���� �ȳ��� ��� -1 ���ָ� ��
    result = 1
    for data in typeClothes:
        num = len(typeClothes.get(data))
        result = result * (num+1)
    answer = result - 1
    
    
    return answer