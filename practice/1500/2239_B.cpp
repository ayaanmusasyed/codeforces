#include <bits/stdc++.h>
using namespace std; 
using ll = long long; 

void solve() { 
    int n; int d; cin >> n >> d; 
    vector<ll> a(2*n); 
    for (int i = 0; i < n; i++) { 
        cin >> a[i];
        a[i + n] = a[i];
    }

    /**
     * If A has gift and B does not, the net effect on happiness is (A - B) 
     * 
     * Thus, if A has a gift, and C of the 2d neighbours have a gift, then H += A(2d - C) 
     * 
     * If not, H += -A(C) 
     * 
     * A*C = sum of weight w/ gifts = S 
     * 
     * Thus, H = sum(2d*A - S)
    */

    // We need to precompute the prefix arrays of X = 2d*A - S
    vector<ll> prefix(2*n); 
    prefix[0] = a[0];
    for (int i = 1; i < 2*n; i++) { 
        prefix[i] = prefix[i - 1] + a[i];
    }

    vector<ll> x(n);
    ll happiness = 0;
    for (int i = 0; i < n; i++) { 
        ll r = 0; 
        ll l = 0;

        // check right
        r = prefix[i + d] - prefix[i];

        if (i - d - 1 >= 0) { 
            l = prefix[i - 1] - prefix[i - d - 1];
        } else { 
            l = prefix[n + i - 1] - prefix[n + i - d - 1];
        }

        x[i] = 2*d*a[i] - (r + l);
        happiness += max(0LL, x[i]);
    }

    cout << happiness << "\n";

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