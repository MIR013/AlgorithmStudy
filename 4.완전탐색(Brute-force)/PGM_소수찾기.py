
#전역변수
stringLen = 0
ans = []

def isPrime(num):
    if num == 0:
        return False
    if num == 1:
        return False
    if num == 2:
        return True

    for i in range(2,int(num ** 0.5)+1):
        if num%i==0:
            return False

    return True

def makeP(num,answer,target,numbers): #수,현재길이,완성길이,입력값,정답
    if len(answer) == target:
        #소수인지 판단
        cnumber = ""
        for idx in range(target):
            cnumber += numbers[answer[idx]]
        cnumber = int(cnumber)
        global ans
        if cnumber not in ans and isPrime(cnumber):#소수이면
            #print(cnumber)
            ans.append(cnumber)

        return answer
    #for문
    for i in range(stringLen): #(0,1)과 (1,0)가 나와야 해서 0부터 시작 단, 자기자신은 불가
        if i != num and i not in answer:#자기자신이 아니어야 하고 리스트에도 있으면 안됨
            answer.append(i)
            makeP(i,answer,target,numbers)
            answer.pop() #맨 뒤에 걸 빼야함 그래야 다음 게 들어갈 수 있다.
    return

def solution(numbers):
    answer = 0
    #만들수 있는 모든 경우의 수
    #17 -> 1,7,17 즉,n개인 경우를 모두 판단

    global stringLen #전역변수 수정 시 사용
    stringLen = len(numbers)

    for i in range(1,stringLen+1): #자리수 판단
        #해당 자리 수로 만들 수 있는 수 추출 - 자기자신 없는 순열
        alist = []
        for idx in range(stringLen):
            #print("get in ",idx,i)
            alist.append(idx) #넣고
            makeP(idx,alist,i,numbers)
            alist.pop() #빼야 다음게 맨 앞으로 온다

    #print(ans)
    answer = len(ans)
    return answer

if __name__ == "__main__":
    numbers = "119"
    sol = solution(numbers)
    print(sol)
