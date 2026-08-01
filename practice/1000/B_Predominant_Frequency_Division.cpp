#include <bits/stdc++.h>
using namespace std; 

void solve() { 
    int n; cin >> n; 
    vector<int> A(n); 
    for (auto &a : A) { 
        cin >> a; 
    }

    vector<int> P(n); 
    vector<int> Q(n); 

    int x = 0; 
    int y = 0;

    for (int i = 0; i < n; i++) {
        int a = A[i]; 

        if (a == 1) { 
            x += 1; 
            y += 1; 
        } 
        else if (a == 2) { 
            x -= 1; 
            y += 1; 
        }
        else { 
            x -= 1; 
            y -= 1; 
        }

        P[i] = x; 
        Q[i] = y;
    }

    int mn = INT_MAX;

    if (P[0] >= 0) {
        mn = Q[0];
    }

    for (int i = 1; i < n - 1; i++) { 
        if (Q[i] - mn >= 0) { 
            cout << "YES\n";
            return;
        }
        if (P[i] >= 0) { 
            mn = min(mn, Q[i]);
        }
    }

    cout << "NO\n";
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