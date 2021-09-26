n = int(input())
l = list()
for i in range(n) :
    s = list(input().split())
    if s[1] == "enter" :
        if s[0] not in l :
            l.append(s[0])
    elif s[1] == "leave" :
        if s[0] in l :
            l.remove(s[0])
l.sort()
l.reverse()
for i in range(len(l)) :
    print(l[i])
            
