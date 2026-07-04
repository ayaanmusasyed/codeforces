t = int(input())

for _ in range(t): 
    s = input().strip()
    n = len(s)

    # prefix count of 2s
    pref2 = [0] * (n + 1)
    for i in range(n):
        pref2[i + 1] = pref2[i] + (s[i] == '2')

    # suffix count of 1s and 3s
    suf13 = [0] * (n + 1)
    for i in range(n - 1, -1, -1):
        suf13[i] = suf13[i + 1] + (s[i] == '1' or s[i] == '3')

    best_keep = 0

    for split in range(n + 1):
        keep = pref2[split] + suf13[split]
        best_keep = max(best_keep, keep)

    answer = n - best_keep
    print(answer)
        