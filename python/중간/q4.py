time = input("시간을 입력하세요. ex)3:47 : ")
if time[-3] == ':' and int(time[-2:]) >= 00 and int(time[-2:]) < 60 and ((time[1] == ':' and int(time[0]) >= 1 and int(time[0]) <= 9) or (time[2]==':' and int(time[:2]) >= 1 and int(time[:2]) <= 12)) :
    if time[-2:] == '00' :
        print("정각입니다.")
    else :
        print("정각이 아닙니다.")
else :
    print("형식이 맞지 않습니다.")
