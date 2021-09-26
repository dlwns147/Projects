def sort(r) :
    for i in range(3) :
        if r[i] == "black" :
            r[i] = 0
        elif r[i] == "brown" :
            r[i] = 1
        elif r[i] == "red" :
            r[i] = 2
        elif r[i] == "orange" :
            r[i] = 3
        elif r[i] == "yellow" :
            r[i] = 4
        elif r[i] == "green" :
            r[i] = 5
        elif r[i] == "blue" :
            r[i] = 6
        elif r[i] == "violet" :
            r[i] = 7
        elif r[i] == "grey" :
            r[i] = 8
        elif r[i] == "white" :
            r[i] = 9

    return (r[0] * 10 + r[1]) * (10 ** r[2])

l = list()

for i in range(3) :
    l.append(input())

print(sort(l))
    
