money = (input("금액을 넣어주세요. : "))
if money[0]=='$' :
    print("환전 금액은", int(money[1:]) * 1200, "원 입니다.")
elif money[0]=='E' :
    print("환전 금액은", int(money[1:]) * 1300, "원 입니다.")
elif money[0]=='Y' :
    print("환전 금액은", int(money[1:]) * 1100, "원 입니다.")
else :
    print("잘못된 입력입니다. ")
