import sys
input = sys.stdin.readline

t = int(input())
for i in range(t) :
    n = int(input())
    l = list(map(int, input().split()))
    x = 0
    for j in range(n - 1) :
        for k in range(n - j - 1) :
            if l[k] > l[k + 1] :
                temp = l[k]
                l[k] = l[k + 1]
                l[k + 1] = temp
                x += 1
    print(x)