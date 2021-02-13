sentence = input("문장을 입력하세요 : ")
word = input("글자를 입력하세요 : ")
if word in sentence :
    print(sentence * 2)
else :
    print(sentence + word)
