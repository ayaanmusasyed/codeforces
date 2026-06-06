#include <bits/stdc++.h>
using namespace std; 

void solve() { 
    int n; cin >> n; 
    vector<int> a(n); 
    for (int i = 0; i < n; i++) { 
        cin >> a[i]; 
    }

    vector<int> f(101, 0); 
    for (int x: a) { 
        f[x] += 1;
    }

    bool possible = true; 
    for (int x = 0; x < 101; x++) { 
        if (f[x] > 1) { 
            possible = false;
        }
    }

    if (!possible) { 
        cout << -1 << "\n";
    } else { 
        sort(a.begin(), a.end()); 
        for (int i = 0; i < n/2; i++) { 
            int temp = a[i]; 
            a[i] = a[n - 1 - i]; 
            a[n - i - 1] = temp;
        }

        for (int i = 0; i < n; i++) { 
            cout << a[i] << " ";
        }

        cout << "\n";
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