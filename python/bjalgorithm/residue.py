l = []
n = 10
for i in range(10) :
    n = int(input()) % 42
    if n not in l :
        l.append(n)
print(len(l))
