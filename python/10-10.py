def vol_chg(c_vol) :
    vol = int(input("증가시킬 만큼의 음량을 입력 : "))
    print("증가 후의 음량은", c_vol + vol, "입니다.")
              
cur_vol = 3
print("현재 음량은", cur_vol, "입니다.")
vol_chg(cur_vol)
