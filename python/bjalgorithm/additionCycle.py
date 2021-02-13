n = input()
i = 0
if int(n) < 10 :
    n += '0'
n1 = n
while True :
    n = n[1] + str((int(n[0]) + int(n[1]))%10)
    i += 1
    if n1 == n :
        break
print(i)
