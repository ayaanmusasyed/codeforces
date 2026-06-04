n, m, a = map(int, input().split())

x = n//a 
y = m // a
if n % a != 0: 
    x += 1
if m % a != 0: 
    y += 1

res = x * y

print(res)