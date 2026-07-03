t = int(input())

for _ in range(t): 
    n = int(input())

    factors = []
    f = 1
    while (f*f <= n): 
        if (n % f == 0):
            factors.append(f)
            if f != n//f:
                factors.append(n // f)
        f += 1

    factors.sort()   
    for j in factors: 
        if pow(j, n, n) == 0: 
            print(j)
            break
    