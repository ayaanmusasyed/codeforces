#include <bits/stdc++.h>
using namespace std; 

void solve() { 
    // number fo 1s can either +2 or -2 -> check parity of 1s at i mod k 
    int n; int k; cin >> n >> k;
    string s; cin >> s; 

    map<int, int> f; 
    for (int i = 0; i < k; i++) { 
        f[i] = 0; 
    }

    for (int i = 0; i < n; i++) { 
        if (s[i] == '1') { 
            f[i % k] += 1;
        }
    }

    bool ans = true; 
    for (int i = 0; i < k; i++) { 
        if (f[i] % 2 == 1) { 
            ans = false; 
            break;
        }
    }

    if (ans) {
         cout << "YES\n";
    } else { 
        cout << "NO\n";
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