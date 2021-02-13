print("201710272 이상준 입니다.")
session = int(input("수료 학기를 입력하세요. : "))
grade = float(input("학점을 입력하세요. : "))

if session==0 or session >8 :
    print("장학금을 받을 수 없습니다.")
elif grade >= 4.0 :
    print("전액 장학금을 받을 수 있습니다.")
elif grade >= 3.5 :
    print("50% 장학금을 받을 수 있습니다.")
elif grade >= 3.0 :
    print("30% 장학금을 받을 수 있습니다.")
else :
    print("장학금을 받을 수 없습니다.")
