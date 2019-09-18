import operator

def solution(genres, plays):
    answer = []
    

    genr={}#장르:총 재생횟수
    genr_list={}#장르:[노래번호,재생횟수] - 재생 횟수 순, 번호 작은 순
    n = len(plays)
    #초기화

    for index in range(n):
        kinds = genres[index]
        if genr.get(kinds):
            genr[kinds] += plays[index]
            genr_list[kinds].append([index,plays[index]])
        else:
            genr[kinds] = plays[index]
            genr_list[kinds] = [[index,plays[index]]]
          
    #특정 장르 내부에서 재생횟수 -> 노래번호 순으로 정렬
    for g in genr_list.keys():
        #소팅합니다. 두번째 인자는 내림차순 첫번재 인자는 오름차순
        genr_list[g] = sorted(genr_list[g],key=lambda x: (-x[1], +x[0]))
    
    #장르의 총 노래 수가 큰 것 부터
    genr = sorted(genr.items(), key=operator.itemgetter(1),reverse=True)
    
    for g in genr:
        #앞에서 두곡 선택(한곡만 존재할 수도 있음, 존재하지 않는 경우는 아예 안들어옴)
        time = 0
        for data in genr_list[g[0]]:
            #print(data)
            if(time>=2):
                break
            answer.append(data[0])
            time += 1

        
    
    
    return answer