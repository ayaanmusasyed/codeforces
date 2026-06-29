#include <bits/stdc++.h>
using namespace std; 
using ll = long long; 

void solve() { 
    int n; cin >> n; 
    vector<ll> a(n); 
    for (int i = 0; i < n; i++) { 
        cin >> a[i];
    }

    /**
     * We always invert leftmost: 
     * 
     * 1) (x, y, z) -> (x, z, y + z) -> (z, x + z, y + z) -> (z, y + z, x + y + 2z)
     * 
     * 2) (x, y, z) -> (y, x + z, z) -> (y, z, x + y + z)
     * 
     * Thus, case 2 leads to smaller end total. 
    */

    for (int i = 0; i < n - 1; i++) { 
        if (a[i + 1] < a[i]) { 
            ll temp = a[i + 1]; 
            a[i + 1] += a[i]; 
            a[i] = temp;  
        }
    }

    cout << a[n - 1] << "\n";
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