l = int(input())
x = 0
for _ in range(l):
    s = str(input())
    if s[1] == "+": 
        x += 1
    else: 
        x -= 1
print(x)