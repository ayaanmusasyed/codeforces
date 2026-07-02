#include <bits/stdc++.h>
using namespace std; 

void solve() { 
    int n; int m; int d; cin >> n >> m >> d; 
    int max_height = 1 + d / m;

    int ans = 0; 
    if (max_height >= n) {
        ans = 1;
    } else { 
        if (n % max_height == 0) { 
            ans = n / max_height;
        } else { 
            ans = n / max_height + 1;
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