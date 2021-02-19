for i in range(int(input())) :
    l = input()
    n = 0
    m = 0
    for j in range(len(l)) :
        if l[j] == "O" :
            m += 1
        if l[j] == 'X' or j == (len(l) - 1):
            n += int(m * (m + 1) / 2)
            m = 0
    print(n)
