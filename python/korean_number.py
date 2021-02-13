print("201710272 이상준 입니다.")
lucky = int(input("행운의 숫자가 무엇일까요? : "))
k_num = float(input("한국인이 좋아하는 숫자는? : "))

if lucky == 7 :
    if k_num == 3 :
        print("둘 다 맞췄습니다!")
    else :
        print("행운의 숫자만 정답입니다.")
else :
    if k_num == 3 :
        print("한국인이 좋아하는 숫자만 정답입니다.")
    else :
        print("둘 다 오답입니다.")
