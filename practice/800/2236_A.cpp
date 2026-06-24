#include <bits/stdc++.h>
using namespace std; 

void solve() { 
    int n; cin >> n; 
    int p = 0; int q = 10; // max and min
    int a; 
    for (int i = 0; i < n; i++) { 
        cin >> a; 
        p = max(p, a); 
        q = min(q, a);
    }

    cout << p - q + 1 << "\n";
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