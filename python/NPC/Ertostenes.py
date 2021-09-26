n, k = map(int,input().split())
l = list(range(2, n + 1))
while l :
    i = l[0]
    c = 1
    while c * i <= l[-1] :
        if c * i in l :
            if k == 1 :
                print(c * i)
                exit()
            else :
                l.remove(c * i)
                k -= 1       
        c += 1