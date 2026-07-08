#include <bits/stdc++.h>
using namespace std; 

void solve() { 
    int n; cin >> n; 
    vector<int> a(n); 
    int m = INT_MAX;
    for (int i = 0; i < n; i++) { 
        cin >> a[i]; 
        m = min(m, a[i]);
    }

    int k = 0; 

    // case 1: use x >= m -> make every element 0

    // case 2: use x >= q -> make every element m
    // q = min(a[i] - m)

    int q = INT_MAX;
    for (int i = 0; i < n; i++) { 
        if (a[i] != m) { 
            q = min(q, a[i] - m);
        }
    }

    k = max(m, q); 

    cout << k << "\n";
    
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