def solution(answers):
    answer = []
    #1:1,2,3,4,5
    #2:2,1,2,3,2,4,2,5
    #3:3,3,1,1,2,2,4,4,5,5
    p1=(1,2,3,4,5)
    p2=(2,1,2,3,2,4,2,5)
    p3=(3,3,1,1,2,2,4,4,5,5)
    score=[0,0,0]

    for idx, ans in enumerate(answers):
        idx1 = idx%5
        if p1[idx1] == ans:
            score[0] += 1
        idx2 = idx%8
        if p2[idx2] == ans:
            score[1] += 1
        idx3 = idx%10
        if p3[idx3] == ans:
            score[2] += 1

    #check max
    maxValue = max(score)
    for idx,data in enumerate(score):
        if data == maxValue:
            answer.append(idx+1)

    answer.sort()

    return answer

if __name__ == "__main__":
    answers = [1,2,3,4,5]
    answers2 = [1,3,2,4,2]
    sol = solution(answers2)
    print(sol)
