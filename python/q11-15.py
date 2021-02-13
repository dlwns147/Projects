def len_square(n1, n2) :
    return 2 * (n1 + n2)

def s_square(n1, n2) :
    return n1 * n2

def print_cal(cal, side1, side2) :
    if cal == 1 :
        print("둘레 : ", len_square(side1, side2))
    else :
        print("넓이 : ", s_square(side1, side2))

while(True) :
    cal = int(input("1. 둘레, 2. 넓이, 3. 종료 : "))
    while cal < 1 or cal > 3 :
        cal = int(input("범위를 벗어났습니다.\n1. 둘레, 2. 넓이, 3. 종료 : "))
    if cal == 3 :
        break
    side1 = int(input("side1 = "))
    side2 = int(input("side2 = "))
    print_cal(cal, side1, side2)
    
