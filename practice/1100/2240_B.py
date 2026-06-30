t = int(input())

for _ in range(t): 
    n,m,r,c= map(int, input().split())
    # we have (n - r + 1)(m - c + 1) equations in our system
    # thus, total dof is nm - (n - r + 1)(m - c + 1)
    mod = 998244353
    dof = n*m - (n - r + 1)*(m - c + 1)

    # use python due to easy power func 
    print(pow(2, dof, mod))
