l = list()
for i in range(0, 9) :
    l.append(int(input()))
print("%d\n%d"%(max(l), (l.index(max(l)) + 1)))
