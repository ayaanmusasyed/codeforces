n = 1000

def digit_sum(x: int): 
    s = str(x)
    d = 0
    for c in s: 
        d += int(c)
    
    return d


res = []
for i in range(1, n): 
    y = digit_sum(i)
    if digit_sum(y) == y: 
        res.append(i)

print(res)
