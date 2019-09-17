
def makeP(isTrue,array,index):
    if len(array)==len(isTrue):
        return

    isTrue[index]=True
    array.append(index)
    makeP(isTrue,array,index+1)


def solution(numbers):
    answer = ''

    #len(numbers)!개의 경우의 수가 나옴
    #100000!가능....? => 그냥 다 찾으면 효율성 측면에서 실패
    #가장 왼쪽의 수가 큰 친구 > 같은데 뒤에 자리수가 없는 친구 > 같으면 그 다음게 같은 친구
    #근데 이렇게 하는게 더 오래걸릴것 같은데

    #숫자 생성 - 모든 경우의 수 구하기(순열)
    isTrue=[]
    for index in range(0,len(numbers)):
        isTrue.append(False)
    for index in range(0,len(numbers)):
        if isTrue[index] == False:
            isTrue[index] = True
            newP = []
            makeP(isTrue,newP,index)
            isTrue[index] = False


    #소팅

    return answer

if __name__ == "__main__":
    numbers = [6,10,2]
    answer = solution(numbers)
    print(answer)
