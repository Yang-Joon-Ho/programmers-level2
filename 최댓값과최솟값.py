def solution(s):
    answer = ''

    int_list = []
    for i in s.split(' '):
        int_list.append(int(i))     

    answer += str(min(int_list))
    answer += ' '
    answer += str(max(int_list))

    return answer
