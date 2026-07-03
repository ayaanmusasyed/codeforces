for n in range(1, 100): 
    k = 1
    while (True): 
        if (pow(k, n, n) == 0): 
            break
        k += 1
    
    print(str(n) + ": " + str(k))
