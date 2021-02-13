def ticket() :
    price_dict = { '춘천' : 5000, 
                  '부산' : 30000,
                  '대구' : 20000,
                  '수원' : 1000 }
    dest = input('한 곳을 입력하세요 : ')
    print(price_dict[dest], "원 입니다.")
