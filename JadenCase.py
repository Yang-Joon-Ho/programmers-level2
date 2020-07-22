def solution(s):
    answer = ''
    
    s = s.lower()
    s_li = s.split(' ')
    
    for i in s_li :
        answer += ' ' + i.capitalize() 

    return answer[1:]
