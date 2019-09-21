def solution(N):
    answer = 0

    #DP로 N까지의 길이 배열 구하고 테두리 길이 구하면 됨
    #DP는 식을 세우고 - 이를 배열에 저장해서 여러번 계산하지 않게 한다!!
    dplist = [1] * N
    for index in range(2,N):
        dplist[index] = dplist[index-1]+dplist[index-2]

    #print(dplist)
    answer = 2*(dplist[N-1]+dplist[N-2])+2*(dplist[N-2]+dplist[N-3])

    return answer