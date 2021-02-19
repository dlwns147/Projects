def d(n) :
    return n + sum(map(int, str(n)))

l = list(range(1, 10001))
for i in l :
    while d(i) <= l[-1] :
        i = d(i)
        try :
            l.remove(i)
        except :
            1
for i in l :
    print(i)
