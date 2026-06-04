for i in range(5):
    row = list(map(int, input().split()))
    for j in range(5): 
        if row[j] == 1: 
            res = max(2 - j, j - 2) + max(i - 2, 2 - i)
            print(res)