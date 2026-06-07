#include <bits/stdc++.h>
using namespace std; 
using ll = long long; 

void solve() { 
    ll p; ll q; cin >> p >> q; 
    
    // let e be the total edges we have
    ll e = p + 2*q; 

    // for a n*m grid, it takes n + m + 2nm edges
    // from p + 2q = n + m + 2mn, we get n = (p + 2q - m)/(2m + 1)
    for (ll m = 1; 2 * m * m < e + 100; m++) { 
        if ((e - m) % (2*m + 1) == 0) { 
            ll n = (e - m)/(2*m + 1);

            if (n >= m && p >= abs(n - m)) { 
                cout << n << " " << m << "\n";
                return;
            }
        }
    }

    cout << -1 << "\n";
}

int main() { 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
    int t; cin >> t;
    
    while (t--) { 
        solve();
    }

    return 0; 
}