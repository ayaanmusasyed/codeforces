#include <bits/stdc++.h>
using namespace std; 

void solve() {
    int n;
    cin >> n;

    for (int fixed = n; fixed >= 0; fixed--) {
        int mask = (1 << fixed) - 1;
        int step = 1 << (fixed + 1);

        for (int x = 0; x < (1 << n); x += step) {
            cout << (x | mask) << ' ';
        }
    }

    cout << '\n';
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