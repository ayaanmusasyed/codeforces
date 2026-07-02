t = int(input())

for _ in range(t):
    n = int(input())
    s = input()
    ans = 0
    while (ans < n and s[ans] != 'L'): 
        ans += 1

    print(ans + 1)