mixlist = [1, 2, 3, "banana", 4, 5, "melon"]
sum = 0
for ele in mixlist :
    if type(ele) == str :
        print(ele, "is a string.")
    elif type(ele) == int :
        print(ele, "is a integer.")
        sum += int(ele)
print(sum)
