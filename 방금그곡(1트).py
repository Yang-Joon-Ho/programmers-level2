def solution(m, musicinfos):
    answer = ''

    # 기억하고 있는 음절 m에서 'C#' = 'c'이런식으로 치환함
    temp = ''
    i = 0
    while i < len(m):
        if i + 1 < len(m) and m[i + 1] == '#':
            temp += m[i].lower()
            i += 1
        else:
            temp += m[i]
        i += 1

    m = temp[:]
    ###############

    # 입력 문자열 , 기준으로 분류
    li = []
    for mu in musicinfos:
        li.append(mu.split(','))
    #######

    # 음악 제목, 시작 시간, 재생 시간을 속성으로 하는 테이블 만듦
    song = []
    for l in li:
        song_temp = []

        song_temp.append(l[2])
        before = int(l[0].split(':')[0]) * 60 + int(l[0].split(':')[1])
        song_temp.append(before)

        if int(l[1].split(':')[0]) == 0:
            after = 24 * 60
        else:
            after = int(l[1].split(':')[0]) * 60 + int(l[1].split(':')[1])

        song_temp.append(after - before)

        song.append(song_temp)
    #################

    # 앞서 만든 테이블(song)에서 음절 속성을 추가함 ex) ABCDEFABC
    for i in range(len(song)):
        melody = ''

        k = 0
        for j in range(0, song[i][2]):
            if li[i][3][(k + 1) % len(li[i][3])] == '#':
                melody += li[i][3][k % len(li[i][3])].lower()
                k = (k + 1) % len(li[i][3])
            else:
                melody += li[i][3][k % len(li[i][3])]

            k = (k + 1) % len(li[i][3])

        song[i].append(melody)
    ###################

    print(m)
    print(li)
    print(song)

    # 'ABC'와 'aBC'는 다름
    # 기억하고 있는 음이 포함되어 있는 노래들을 찾음
    bigyo = []
    for i in range(0, len(song)):
        if song[i][3].find(m) != -1:
            #return song[i][0]
            bigyo.append(song[i])
    #####

    # 찾고있는 노래가 없으면 None 반환
    if len(bigyo) == 0:
        return "(None)"

    print(bigyo)
    #노래 중 재생 시간이 가장 긴 노래의 재생 시간을 구한다.
    temp_time = 0
    for i in range(len(bigyo)) :
        if temp_time <= bigyo[i][2] :
            temp_time = bigyo[i][2]

    print(temp_time)
    # 위에서 구한 재생시간과 동일한 재생시간을 가진 노래들만 추린다.
    bigyo_bigyo = []
    for i in range(len(bigyo)) :
        if temp_time == bigyo[i][2] :
            bigyo_bigyo.append(bigyo[i])

    # 가장 빠른 재생 시작 시간을 찾는다.
    print(bigyo_bigyo)
    temp_start = 25*60
    #temp_name = ''
    for i in range(len(bigyo_bigyo)) :
        if temp_start > bigyo_bigyo[i][1] :
            temp_start = bigyo_bigyo[i][1]
            #temp_name = bigyo_bigyo[i][0]

    # 위에서 구한 재생 시작 시간과 동일한 재생 시작 시간을 가진 노래들이 여러곡일 경우
    # 알파벳순으로 정렬한다.
    bigyo_bigyo_bigyo = []
    for i in range(len(bigyo_bigyo)) :
        if bigyo_bigyo[i][1] == temp_start :
            bigyo_bigyo_bigyo.append(bigyo_bigyo[i][0])

    bigyo_bigyo_bigyo.sort()

    print(bigyo_bigyo_bigyo)

    return bigyo_bigyo_bigyo[0]
