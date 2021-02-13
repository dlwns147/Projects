import sys

for i in range(0, int(sys.stdin.readline())) :
    x, y = map(int, sys.stdin.readline().rsplit())
    print(x + y)
