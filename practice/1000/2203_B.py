t = int(input())

for _ in range(t): 
    # x is beautiful iff F(x) <= 9 
    x = int(input())

    digits = {i: 0 for i in range(10)}    
    s = str(x)
    d = 0
    leading_d = 0
    for i in range(len(s)):
        c = s[i]
        z = int(c)
        if (i > 0): 
            digits[z] += 1
        else: 
            digits[z - 1] += 1
        d += z
    
    if (d < 10): 
        print(0)
    else: 
        moves = 0
        curr = 9 
        while (curr > -1 and d > 9): 
            while (digits[curr] > 0 and d > 9):
                d -= curr 
                digits[curr] -= 1
                moves += 1

            if (d < 10): 
                break
            
            curr -= 1

        print(moves)