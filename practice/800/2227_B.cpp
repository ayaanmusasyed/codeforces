#include <bits/stdc++.h>
using namespace std; 

void solve() { 
    int n; cin >> n; 
    char a; 
    int x = 0; 
    int y = 0; 
    for (int i = 0; i < n; i++) { 
        cin >> a; 
        if (a == '(') { 
            x += 1; 
        } else { 
            y += 1;
        }
    }

    if (x == y) { 
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