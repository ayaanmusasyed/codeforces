t = int(input())

for _ in range(t): 
    n, k = map(int, input().split())
    
    # use 2^i - 1 as it has the smallest value per popcount 
    # popcount(3) == popcount(5) == 2 -> we can use 3s more than 5s     
    values = []
    i = 1

    # for 1st bit cost 1, 2nd bit 2, 3rd bit 4, etc etc 
    ans = 0
    p = 1
    while n >= p: 
        t = min(k, n // p)
        ans += t
        n -= t * p
        p *= 2

    print(ans)




        
