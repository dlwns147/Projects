mer = { '비누' : [3, 2], '칫솔' : [5, 4], '샴푸' : [2, 1], '치약' : [4, 4], '로션' : [5, 3]}

if mer['비누'][0] >= 4 and mer['비누'][1] >= 4 :
    print('비누는 우수 상품 입니다.')
elif mer['비누'][0] < 4 and mer['비누'][1] < 4 :
    print('비누는 판매 중지 상품 입니다.')
    
if mer['칫솔'][0] >= 4 and mer['칫솔'][1] >= 4 :
    print('칫솔은 우수 상품 입니다.')
elif mer['칫솔'][0] < 4 and mer['칫솔'][1] < 4 :
    print('칫솔은 판매 중지 상품 입니다.')

if mer['샴푸'][0] >= 4 and mer['샴푸'][1] >= 4 :
    print('샘푸는 우수 상품 입니다.')
elif mer['샴푸'][0] < 4 and mer['샴푸'][1] < 4 :
    print('샴푸는 판매 중지 상품 입니다.')

if mer['치약'][0] >= 4 and mer['치약'][1] >= 4 :
    print('치약은 우수 상품 입니다.')
elif mer['치약'][0] < 4 and mer['치약'][1] < 4 :
    print('치약은 판매 중지 상품 입니다.')

if mer['로션'][0] >= 4 and mer['로션'][1] >= 4 :
    print('로션은 우수 상품 입니다.')
    
if mer['로션'][0] < 4 and mer['로션'][1] < 4 :
    print('로션은 판매 중지 상품 입니다.')
else :
    print("로션은 판매 중지 상품이 아닙니다.")
    
print("201710272 이상준 입니다.")
