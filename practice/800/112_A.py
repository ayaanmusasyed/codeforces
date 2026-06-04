x = str(input())
y = str(input())

x = x.lower()
y = y.lower()
if x == y: 
    print(0)
elif x < y: 
    print(-1)
else: 
    print(1)