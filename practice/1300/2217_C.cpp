#include <bits/stdc++.h>
using namespace std; 

void solve() { 
    int n; int m; int a; int b; cin >> n >> m >> a >> b; 
    bool cover = false; 
    if ((gcd(n, a) == 1) && (gcd(m,b) == 1) && (gcd(n,m) <= 2)) { 
        cover = true; 
    }

    if (cover) { 
        cout << "YES" << "\n";
    } else { 
        cout << "NO" << "\n";
    }
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