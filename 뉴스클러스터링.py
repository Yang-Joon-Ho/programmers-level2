def str(str):

    li = []
    for i in range(0, len(str) - 1):
        if str[i].isalpha() and str[i+1].isalpha():
            li.append(str[i] + str[i + 1])

    return li


def solution(str1, str2):
    answer = 0

    str1 = str1.lower()
    str2 = str2.lower()

    str1_li = str(str1)
    str2_li = str(str2)

    intersect = []
    str2_temp = str2_li[:]

    #교집합 찾기
    for i in str1_li:
        if i in str2_temp:
            intersect.append(i)
            str2_temp.remove(i)

    #합집합 찾기
    for i in str1_li:
        if i in str2_li:
            str2_li.remove(i)

    union = str1_li + str2_li

    if(len(union) == 0) :
        return 65536
    else :
        return int(len(intersect) / len(union) * 65536)
