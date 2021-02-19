for i in range(int(input())) :
    n2 = 0
    l = list(map(int, input().split()))
    m = (sum(l[1:]) / l[0])
    for j in range(1, len(l)) :
        if l[j] > m :
            n2 += 1
    print('%.3f%%'%(n2 / l[0] * 100))
