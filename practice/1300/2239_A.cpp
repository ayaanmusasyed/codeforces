#include <bits/stdc++.h>
using namespace std; 
using ll = long long; 

void solve() { 
    int n; cin >> n; 
    ll mod = 998244353;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) { 
        cin >> a[i]; 
    }

    ll ans = 0;
    if (n != 1) { // if length = 1, then Alice cannot win as per example contradiction
        // to make alice win, we just need to make at least 1 of the elements 0
        // corrected via editorial: a player can win on their turn if there is more than 1 non-zero element 

        ll X = a[0];
        for (int i = 1; i < n; i++) { 
            X = X ^ a[i]; 
        } 

        if (X == 0) { 
            ans = 1; // b array is just original 
        } else { 
            for (int i = 0; i < n; i++) {
                ll y = a[i] ^ X;
                if (y <= a[i]) { 
                    ans += 1;
                }
            }
        }
    }

    cout << ans << "\n";
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