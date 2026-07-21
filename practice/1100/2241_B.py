t = int(input())

for _ in range(t): 
    x = int(input())
    d = len(str(x))

    # y = 10^d + 1 works by construction 
    print(pow(10,d) + 1)