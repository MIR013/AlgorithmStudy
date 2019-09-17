def byFor(phone_book):
    
    phone_book.sort()#앞에 짧은게 오면 덜 비교해도 됨
    
    #str이 포함되어있는지 확인하는 함수 string.startswith(비교자)
    length = len(phone_book)
    for i in range(0,length):
        for j in range(i+1,length):
            if(phone_book[j].startswith(phone_book[i])):
                #더 비교하면 안댐
                return False
    return True

def solution(phone_book):
    answer = True
    
    #str이 포함되어있는지 확인하는 함수 string.startswith(비교자)
    answer = byFor(phone_book)
    
    #hash..의미 있는가 
    #for문할때 너무 오래걸리면 hash로 바꾸고 아니면 for쓰는게..
    
    
    return answer