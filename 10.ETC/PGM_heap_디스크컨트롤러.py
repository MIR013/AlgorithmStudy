import heapq as hq
import operator
def solution(jobs):
    answer = 0
    pq=[]
    in_time=-1 #
    current_time = 0#현재 흐르는 시간
    count = 0 #job을 추가한 횟수 저장
    length = len(jobs)
    
    #시간이 더 중요해서 시간기준으로 만든다
    #heap은 유동적으로 추가하여서 소팅할대 효과적이다. -> 여기서도 그렇게 사용해야한다.
    #초당 계속 계산하면 최대는 500*1000 = 500000이니까 1초내에 돌긴 할 듯
    
    #즉, 일이 수행할게 있으면그 직업만큼 수행해 버리고, 아니면 1초씩 늘어나게 한다.
    #평균대기시간도 (내 프로그램 동작시간 + 대기시간)이며 
    #대기시간은 이전에 한 프로그램들으이 수행시건이기 때문에 미리 전부 더해준다
    
    while count<length:
        #넣을 수 있는 작업 넣기
        for job in jobs:
            #들어가는 시간과 나오는 시간 사이에 있으면 넣어준다.
            if in_time<job[0]<=current_time:
                answer += (current_time-job[0])#프로그램 대기시간을 더해준다 (시작 전 대기시간)
                hq.heappush(pq,job[1])#이제 sjf니 수행시간을 기준으로 넣는다
        #대기하고 있는 job이 있는지
        if len(pq)>0:
            #힙의 맨 앞에거를 실행시켜준다(이때, 현재 시간은 수행시간 만큼 뛰어 넘겨 준다.)
            now = hq.heappop(pq)
            in_time = current_time #들어가는 시간을 현재시간으로 바꾼다(시간의 변화)
            current_time += now
            count += 1
            #이 job을 수행했을때, 본인 포함 나머지 힙 속의 job들이 대기할 시간을 더해준다. - 그래야 본인의프로그램 동작시간이 더해짐
            answer += ((len(pq)+1)*now)
            
        else:#대기하는게 없으면 그냥 넘긴다.
            current_time += 1
        

    return answer//length