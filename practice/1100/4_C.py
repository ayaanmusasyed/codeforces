l = int(input())
database = {}
for _ in range(l):
    s = str(input())
    if s not in database: 
        print("OK")
        database[s] = 1
    else: 
        print(s + str(database[s]))
        database[s] += 1
