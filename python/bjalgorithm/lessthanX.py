n, x = map(int, input().split())
l= list(map(int, input().split()))
for i in range(0, n) :
    if l[i] < x :
        print(l[i], end = ' ')
