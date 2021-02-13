idols = {'A' : (5.6, 9.5), 'B' : (9.1, 9.2), 'C' : (4.3, 3.2), "D" : (9.7, 8.9)}
idol = input("누구의 결과가 궁금하세요? : ")
if idols[idol][0] >= 9.0 and idols[idol][1] >= 9.0 :
    print("자동 진출 입니다.")

elif idols[idol][0] < 5.0 and idols[idol][1] < 5.0 :
    print("탈락 입니다.")

else :
    print("선발전 입니다.")
