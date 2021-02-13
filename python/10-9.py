def tempchg(cur_temp) :
    temp = int(input("조정하고자 하는 만큼의 크기를 입력 : "))
    if temp > 5 or temp < 0 :
        print("잘못 된 범위입니다.")
    else :
        print("조정한 후의 템포는", cur_temp + temp, "입니다.")
    
current = 0
print("현재 템포는", current, "입니다. 템포 조정은 0부터 5까지 가능합니다.")
tempchg(current)
