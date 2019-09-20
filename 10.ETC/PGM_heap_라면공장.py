import heapq

#왜 시간초과인가? for문에 break안걸어서 그런감

def solution(stock, dates, supplies, k):
    answer = -1 #맨 첫타임도 포함되서
    current_time = 0
    last_time = 0#이전에 넣었던 것은 안넣고 리스트도 새로 만들지 않기 위해
    addition = []
    #미래를 보고 뭘 받을지 경정하는 것이 아니라
    # 일단 다 쓰고 그 후에 뭘 받으면 좋을지 선택하는게 알고리즘 상 좋을듯
    # 스토리는 미래지만 뭐 굳이 안그래도 되니까!
    # 그래서 stoke는 0으로 유지될 듯
    
    #초기화 안하면 1 time때 용 코드 짜줘야함
    heapq.heappush(addition,-stock)
    while current_time<k:# <=을 쓰게되면 마지막 날인데도 또 공급을 받게 됨
        #힙에 넣읍시다!!
        for index,date in enumerate(dates): #공급일 기준으로
            if(last_time < date <= current_time):#이전꺼는 이미 힙에 들어가 있으니 안넣겠다
                heapq.heappush(addition,-supplies[index])#공급량을 넣어야 이게 큰거대로 받아올 것. max heap이라 반대로 넣음
            if date > current_time: #오름차순이라서
                break

            
        #수량큰거 가져와서 선택
        next_stock = -1 * heapq.heappop(addition)
        #날짜 넘기기 - 아니지 공급 수량을 더해줘야지 하루에 한개니까
        last_time = current_time
        current_time += next_stock
        answer += 1
    
    return answer