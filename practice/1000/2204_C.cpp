#include <bits/stdc++.h>
using namespace std; 
using ll = long long; 

void solve() { 
    ll a; ll b; ll c; ll m; cin >> a >> b >> c >> m; 

    ll d = lcm(a, b); 
    ll e = lcm(a, c); 
    ll f = lcm(b, c); 

    ll g = lcm(d,c); 

    ll ans1 = 6*(m / a) - 3*(m / d) - 3*(m / e) + 2*(m/g);
    ll ans2 = 6*(m / b) - 3*(m / f) - 3*(m / d) + 2*(m/g);
    ll ans3 = 6*(m / c) - 3*(m / f) - 3*(m / e) + 2*(m/g);

    cout << ans1 << " " << ans2 << " " << ans3 << "\n";
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