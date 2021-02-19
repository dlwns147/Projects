l = []
for i in range(3) :
    l.append(int(input()))
s = str(l[0] * l[1] * l[2])
for i in range(10) :
    print(s.count(str(i)))
