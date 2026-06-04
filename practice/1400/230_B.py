# Number is T-prime if it's a square of a prime: 
n = int(input())
nums = list(map(int, input().split()))
m = max(nums)
m = int(m**0.5) + 1

T_primes = set()
i = 2

# Sieve primes - O(n lg lg n)
#Create a boolean list to track prime status of numbers
prime = [True] * (m + 1)
p = 2
prime[0] = False 
prime[1] = False 

# Sieve of Eratosthenes algorithm
while p * p <= m:
    if prime[p]:

        # Mark all multiples of p as non-prime
        for i in range(p * p, m + 1, p):
            prime[i] = False

    p += 1

# Collect all prime numbers
for p in range(2, m + 1):
    if prime[p]:
        T_primes.add(p*p)


for j in range(n): 
    if nums[j] in T_primes: 
        print("YES")
    else: 
        print("NO")

