n = int(input("1 이상의 정수 입력 : "))
divisor = 1
print(n, "의 약수")
while divisor <= n :
    if n % divisor == 0 :
        print(divisor)
    divisor += 1
