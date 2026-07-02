n = 100

d = {i: [] for i in range(1, n + 1)}

for i in range(1, n + 1): 
    for j in range(1, 10000): 
        if (j & i == j): 
            d[i].append(j)

    print(str(i) + ": " + str(d[i]))