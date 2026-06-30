#include <bits/stdc++.h>
using namespace std; 

void solve(const vector<int>& primes) { 
    int n; cin >> n; 
    // idea is total layers T = (number of prime factors) + q - 1, where q is the sum of all powers 
    // this is cause every divisor has the same pool of primes, so any two divisors w two prime factors can have non-1 gcd 
    // u is number of unique primes, q is sum of all powers 

    int u = 0; int q = 0;
    for (int i = 0; i < primes.size(); i++) { 
        int p = primes[i]; 
        if (p > n) { 
            break;
        } else { 
            if (n % p == 0) { 
                u += 1; 
                while (n % p == 0) { 
                    n = n / p;
                    q += 1;
                }
            }
        }
    }

    int ans = u + q - 1;
    cout << ans << "\n";

}

int main() { 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
    int t; cin >> t;
    
    int lim = 1e6 + 1;
    vector<bool> isPrime(lim, true); 
    isPrime[0] = false;
    isPrime[1] = false; 

    int i = 2; 
    while (i*i < lim) { 
        if (isPrime[i]) { 
            int j = i*i; 
            while (j < lim) { 
                isPrime[j] = false;
                j += i;
            }
        }

        i += 1;
    }

    vector<int> primes; 
    for (int i = 2; i < lim; i++) { 
        if (isPrime[i]) { 
            primes.push_back(i);
        }
    }

    while (t--) { 
        solve(primes);
    }

    return 0; 
}