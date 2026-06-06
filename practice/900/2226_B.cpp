#include <bits/stdc++.h>
using namespace std; 

void solve() { 
    int n; 
    cin >> n; 
    vector<int> p(n);
    for (int i = 0; i < n; i++) { 
        cin >> p[i];
    }

    int good = 0; 
    // Mg - mg = g --> (M - m) = 1
    for (int i = 0; i < n - 1; i++) { 
        if (abs(p[i + 1] - p[i]) == gcd(p[i + 1], p[i])) { 
            good += 1;
        }
    }
    cout << good << "\n";
}

int main() { 
    int t; cin >> t;

    while (t--) { 
        solve();
    }

    return 0; 
}