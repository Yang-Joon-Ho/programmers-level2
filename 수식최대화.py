import itertools

def solution(expression):

    # 숫자와 연산자 
    numbers, operations = [], []
    temp_num = ''
    for i in expression:
        if i.isdigit():
            temp_num += i
        else:
            operations.append(i)
            numbers.append(int(temp_num))
            temp_num = ''
    numbers.append(int(temp_num))

    answer = 0
    for order in itertools.permutations(['+','-','*']):
        temp_num = numbers.copy()
        temp_oper = operations.copy()
        for o in order:

            i = 0
            while i < len(temp_oper):
        
                if temp_oper[i] == o :
                    if temp_oper[i] == '*':
                        temp_num[i] *= temp_num[i + 1]
                    elif temp_oper[i] == '+':
                        temp_num[i] += temp_num[i + 1]
                    else :
                        temp_num[i] -= temp_num[i + 1]
                    temp_num.pop(i + 1)
                    temp_oper.pop(i)

                else :
                    i += 1

        answer = max(answer, abs(temp_num[0]))

    return answer
