

def solution(record):
    answer = []
    
    #단순 시뮬레이션
    #1. Enter id nickname/ Leave id nickname/ Change id name의 기능을 구현
    #   공백을 기준으로 파싱 후 기능/아이디/닉네임으로 변수 저장 후 처리하면 될 듯
    #2. 조건 - 닉네임 중복 가능/ 닉네임이 바뀌면 출력물 모두 변경(->마지막로그만 바뀌는 거라 과정이 필요한지-> 딕셔너리 해서 구현하면 끝일 듯)
    #3. 문자열 배열 반환 - 로그 순서를 남겨야 할 듯
    
    personal_info = {}
    for info in record:
        data = info.split(' ')
        if data[0]=='Enter':
            personal_info[data[1]] = data[2] #있던 없던 상관없음 알아서 함
        elif data[0]=='Change':
             personal_info[data[1]] = data[2]
    
    #로그 작성
    for info in record:
        data = info.split(' ')
        if data[0]=='Enter':
            answer.append(personal_info[data[1]]+'님이 들어왔습니다.')
        elif data[0]=='Leave':
            answer.append(personal_info[data[1]]+'님이 나갔습니다.')
            
    
    return answer