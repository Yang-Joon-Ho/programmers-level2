def solution(str1, str2):

    list1 = [str1[n:n+2].lower() for n in range(len(str1)-1) if str1[n:n+2].isalpha()]
    list2 = [str2[n:n+2].lower() for n in range(len(str2)-1) if str2[n:n+2].isalpha()]

    print(set(list1), set(list2))
    tlist = set(list1) | set(list2)
    res1 = [] #합집합
    res2 = [] #교집합

    if tlist:
        for i in tlist:
            res1.extend([i]*max(list1.count(i), list2.count(i)))
            res2.extend([i]*min(list1.count(i), list2.count(i)))

        print(res1, res2)

        answer = int(len(res2)/len(res1)*65536)
        return answer

    else:
        return 65536

str1 = 'aa1+aa2'
str2 = 'AAAA12'

solution(str1, str2)
