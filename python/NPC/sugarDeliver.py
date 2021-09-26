s = int(input())
if not (s % 5) :
    print(s // 5)
else :    
    for i in range((s // 5), -1, -1) :
        if not ((s - (5 * i)) % 3) :
            print(i + ((s - (5 * i)) // 3))
            break

        if not i :
            print(-1)
            break
