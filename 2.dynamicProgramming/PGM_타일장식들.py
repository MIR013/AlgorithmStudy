def solution(N):
    answer = 0

    #DP�� N������ ���� �迭 ���ϰ� �׵θ� ���� ���ϸ� ��
    #DP�� ���� ����� - �̸� �迭�� �����ؼ� ������ ������� �ʰ� �Ѵ�!!
    dplist = [1] * N
    for index in range(2,N):
        dplist[index] = dplist[index-1]+dplist[index-2]

    #print(dplist)
    answer = 2*(dplist[N-1]+dplist[N-2])+2*(dplist[N-2]+dplist[N-3])

    return answer