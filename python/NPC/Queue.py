l = list()
for i in range(int(input())) :
    str = list(input().split())
    
    if str[0] == "front" :
        if l :
            print(l[0])
        else :
            print(-1)
            
    elif str[0] == "back" :
        if l :
            print(l[-1])
        else :
            print(-1)

    elif str[0] == "empty" :
        if l :
            print(0)
        else :
            print(1)

    elif str[0] == "size" :
        print(len(l))

    elif str[0] == "pop" :
        if l :
            print(l[0])
            del l[0]
        else :
            print(-1)
            
    elif str[0] == "push" :
        l.append(str[1])
