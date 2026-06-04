s = str(input())
s = s.lower()
vowels = {'a','e','i','o','u','y'}
res = ""
for c in s: 
    if c not in vowels: 
        res += "."
        res += c
print(res)