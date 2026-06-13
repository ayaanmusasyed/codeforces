#include <bits/stdc++.h>
using namespace std; 

void solve() { 
    // step will always be even, only ONE coordinate can be odd 
    int x; int y; cin >> x >> y; 
    if ((x % 2 == 1) && (y % 2 == 1)) { 
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
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