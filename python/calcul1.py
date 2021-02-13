print("201710272 이상준 입니다.")
cal=int(input("원하는 연산 번호를 입력하세요 : "))
if 1<=cal<=4 :
    num1=int(input("양의 정수 하나를 입력하세요 : "))
    num2=int(input("양의 정수 다른 하나를 입력하세요 : "))
    if cal==1 :
        print("연산의 결과는", num1+num2 ,"입니다.")
    elif cal==2 :
        print("연산의 결과는", num1-num2 ,"입니다.")
    elif cal==3 :
        print("연산의 결과는", num1*num2 ,"입니다.")
    else :
        print("연산의 결과는", num1/num2 ,"입니다.")
else :
    print("연산 번호를 재입력하세요")
