def solution(clothes):
    answer = 0
    
    #각 종류에 따라 해시(딕셔너리) 생섯
    typeClothes={}
    for data in clothes:
        if(typeClothes.get(data[1])):
            typeClothes.get(data[1]).append(data[0])
        else:
            typeClothes[data[1]] = [data[0]]
    
    #만들 수 있는 세트 만들기
    #자기가 안나올 확률까지해서 길리 +1 한후 전부 안나올 경우 -1 해주면 됨
    result = 1
    for data in typeClothes:
        num = len(typeClothes.get(data))
        result = result * (num+1)
    answer = result - 1
    
    
    return answer