#전역변수
possible = [] #답이 될 가능성이 있는 애들
pernList = [] #경우의 수 저장

def makeP(i,pern,target): #현재수,경우의수리스트,목표길이
    if len(pern) == target:
        global pernList
        data = pern[:] #슬라이싱 하면 얕은 복사가 된다.
        '''
        또는
        import copy
        1. 얕은 복사
            data = copy.copy(pern)
        2. 깊은 복사(주소복사)
            data = copy.deepcopy(pern)
        '''
        pernList.append(data) #list라서 주소를 저장하기 때문에 얕은 복사를 사용해야 한다.
        return

    for idx in range(i+1,3): #얘는 (0,1)과 (1,0)이 같기 때문에 이렇게 시작
        pern.append(idx)
        makeP(idx,pern,target)
        pern.pop()

    return
def solution(baseball):
    answer = 0
    #맨 처음 조건에서 가능한 수를 다음 조건을 거쳐가면서 삭제하는 방법

    global pernList
    for index,game in enumerate(baseball):
        #답은 무조건 세자리수
        #스트라이크 -> 볼

        #스트라이크 수에 따라 경우의 수 생성 ex)s=2 ->(0,1)(0,2)(1,2)
        pern=[]#경우의 수
        for i in range(0,3):
            pern.append(i)
            makeP(i,pern,game[1])
            pern.pop()

        #경우의 수에 따라 가능한 경우 추측하기(0개도 유의)
        number = [game[0]//100,int(game[0]%100)//10,int(game[0]%10)]#idx사용을 위해 list로 변경

        for pos in pernList:
            npos=[]#스트라이크가 아닐것 같은 곳에 0~9의 값을 넣는다
            for i in [0,1,2]:
                if i not in pos:
                    npos.append(i)

            alternate = [] #후보자들
            for idx in range(len(npos)):
                tnumber = number[:]
                for i in range(0,10):
                    tnumber[npos[idx]] = i
                    alternate.append(tnumber)

            #첫번째에선 다 넣고 그 다음부터는 삭제하는 방향으로
            if idnex != 0:
                #possible에 있는지 확인하고 있으면 possible 재구성
                new_alternate = []
                for data in alternate:
                    if data in possible:
                        new_alternate.append(data)
                alternate = new_alternate[:]
            possible = alternate[:]

        #볼 개수에 따라 추측하기 -> 0스트라이크 때문에 따로 반복문을 돌림
        #볼 개수: 0,1,2,3 - 에 따라 경우의 수 생성
        pernList=[]
        pern=[]#경우의 수
        for i in range(0,3):
            pern.append(i)
            makeP(i,pern,game[2])
            pern.pop()
        for pos in pernList:
            tnumber = number[:]


        #경우의 수 초기화
        pernList=[]

    return answer

if __name__ == "__main__":
    baseball = [[123, 1, 1], [356, 1, 0], [327, 2, 0], [489, 0, 1]]
    baseball2 =[[123,2,1]]
    sol = solution(baseball2)
    print(sol)
