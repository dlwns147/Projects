s = ""

n = 5
while n >0 :
    n -= 1
    if (n%2) == 0:
        s = ""

    a = ['foo','bar','baz']
    while a:
        s += str(n) + a[-1]
        del a[-1]

        if len(a) < 2 :
            break

print(s)
