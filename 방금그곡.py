def change(melody):
    if 'A#' in melody: melody = melody.replace('A#', 'a')
    if 'C#' in melody: melody = melody.replace('C#', 'c')
    if 'D#' in melody: melody = melody.replace('D#', 'd')
    if 'F#' in melody: melody = melody.replace('F#', 'f')
    if 'G#' in melody: melody = melody.replace('G#', 'g')
    return melody

def solution(m, musicinfos):
    m = change(m)
    answer = ('(None)', None)
    for info in musicinfos:
        start, end, title, melody = info.split(',')
        start_h, start_m, end_h, end_m = map(int, start.split(':') + end.split(':'))
        time = 60*(end_h-start_h) + (end_m-start_m)
        melody = change(melody)
        
        
        melody_played = (melody*time)[:time]

        print(('ABCD' * 1)[:8])

        # 찾는 음절이 재생된 노래 안에 있고, 
        # 노래 길이가 기존의 노래보다 긴 경우 
        # 정답으로 함. 
        # 노래 길이까지 같은 경우 재생 시작 시간이 빠른걸 정답으로 해야하는데
        # 이미 musicinfos 자체가 재생 시작 시간 순으로 정렬되어 와서 
        # 상관없는듯 ㅋ
        if m in melody_played:
            if (answer[1] == None) or (time > answer[1]):
                answer = (title, time)
    return answer[0]


m = 'ABCDEFG'
musicinfos = ["12:00,12:14,HELLO,CDEFGAB","13:00,13:05,WORLD,ABCDEF"]
solution(m, musicinfos)
