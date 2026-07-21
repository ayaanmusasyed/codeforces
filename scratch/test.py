def isGood(x): 
    s = str(x) 
    d = {i: 0 for i in range(10)}
    for c in s: 
        d[int(c)] += 1
    
    y = 0
    for i in range(10): 
        if d[i] > 0: 
            y += 1
    
    return (y <= 2)

x = 6767
y = 2
while not isGood(x*y): 
    y += 1

print(x)
print(y)
print(x*y)