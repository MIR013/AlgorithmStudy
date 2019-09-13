def solution(array, commands):
    answer = []

    for data in commands:
        new_array=[]
        i = data[0]
        j=data[1]
        k=data[2]

        new_array = array[i-1:j]
        new_array.sort()
        answer.append(new_array[k-1])

    return answer

#atom 실행은 ctrl+shift+b
if __name__ == "__main__":
    array = [1,5,2,6,3,7,4]
    commands = [[2,5,3],[4,4,1],[1,7,3]]
    answer = solution(array,commands)
    print(answer)
