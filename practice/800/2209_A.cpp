#include <bits/stdc++.h>
using namespace std; 
using ll = long long;

void solve() { 
    int n; ll c; ll k; cin >> n >> c >> k; 
    vector<int> a(n); 
    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
    }

    sort(a.begin(), a.end());
    
    // my idea is to greedily use the flip flops when possible 
    for (int i = 0; i < n; i++) { 
        // at each monster, we can use up to (c - a_i) flip flops 
        if (a[i] > c) { 
            break;
        } else { 
            int used_ff = min(c - a[i], k);
            k -= used_ff;
            c += a[i] + used_ff;
        }
    }

    cout << c << "\n";
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