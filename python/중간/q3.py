phone = input("전화번호를 입력하세요. ex)010-1234-5678 : ")
if len(phone) != 13 or phone[3] != '-' or phone[8] != '-' :
    print("형식이 잘못 되었습니다. ")
elif phone[:3] == '011' :
    print("SKT 사용자 입니다.")
elif phone[:3] == '016' :
    print("KT 사용자 입니다.")
elif phone[:3] == '019' :
    print("LGU 사용자 입니다.")
elif phone[:3] == '010' :
    print("통신사를 알 수 없습니다.")
else :
    print("형식이 잘못 되었습니다. ")
