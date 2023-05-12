def solution(m, musicinfos):
    answer = []
    sharps_dict = {
        'A#': 'a',
        'C#': 'c',
        'D#': 'd',
        'F#': 'f',
        'G#': 'g'
    }

    '''
    Compute.
    '''
    for key, value in sharps_dict.items():
        m = m.replace(key, value)

    for musicinfo in musicinfos:
        time1, time2, title, contents = musicinfo.split(',')
        
        time1_h, time1_m = map(int, (time1.split(':')))
        time2_h, time2_m = map(int, (time2.split(':')))
        duration = (time2_h * 60 + time2_m) - (time1_h * 60 + time1_m)
        
        for key, value in sharps_dict.items():
            contents = contents.replace(key, value)
        
        content_length = len(contents)
        contents = contents * (duration // content_length) + contents[:(duration % content_length)]
        
        if m in contents:
            answer.append([title, duration])

    '''
    Output.
    '''
    if not answer:
        return '(None)'
    
    answer.sort(key=lambda x: -x[-1])

    return answer[0][0]
