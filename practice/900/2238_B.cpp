#include <bits/stdc++.h>
using namespace std; 
using ll = long long; 

void solve() { 
    int n; cin >> n; 

    // idea: we iterate the middle value b, the number of (?, x, ?) is based on how many ints from 1 ot n are divisible by x, 
    // specifically y^2 for y ints that are divisible
    ll ans = 0; 

    // there are floor(n/x) ints divisible by x from 1 to n 
    for (int i = 1; i <= n; i++) { 
        ll num_div = n / i;
        ans += pow(num_div, 2);
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