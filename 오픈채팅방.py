def solution(record):
    answer = []

    dict = {}
    li = []
    for r in record:
        temp_r = r.split(' ')

        li_temp = []
        li_temp.append(temp_r[1])
        li_temp.append(temp_r[0])
        li.append(li_temp)

        if len(temp_r) == 3:
            dict[temp_r[1]] = temp_r[2]

    for l in li:
        if l[1] == 'Enter':
            temp_string = dict[l[0]] + "님이 들어왔습니다."
        elif l[1] == 'Leave':
            temp_string = dict[l[0]] + "님이 나갔습니다."
        else:
            continue
            
        answer.append(temp_string)

    return answer
