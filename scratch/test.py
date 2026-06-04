nums = [7,7,7,7,7]

# graph? - V is index and E is the difference between the two index elements 
edges = [] 
edge_idx = {}
n = len(nums)
neighbours = {i : [] for i in range(n)}
x = 0
for i in range(n): 
    for j in range(i + 1, n): 
        edges.append((i, j, nums[j] - nums[i]))
        edge_idx[(i, j)] = x
        neighbours[i].append((j, nums[j] - nums[i]))
        x += 1

m = len(edges)
used = [False for i in range(m)]

i = 0
total = 0 

while i < m:
    if used[i] == False: 
        chain = []
        chain.append(edges[i])
        has_neighbours = True 

        while has_neighbours:
            frm = chain[-1][0] 
            nxt = chain[-1][1]
            diff = chain[-1][2]
            used[edge_idx[(frm, nxt)]] = True 


            one_neighbour = False
            for v in neighbours[nxt]: 
                if v[1] == diff: 
                    chain.append((nxt, v[0], diff))
                    one_neighbour = True 
            
            if not one_neighbour: 
                has_neighbours = False
        
    # based on length of chain we add to total 
    p = len(chain) + 1
    if p >= 3: 
        t = p*(p + 1)//2 - p - (p - 1)
    else: 
        t = 0
    
    total += t

    i += 1
    
print(total)