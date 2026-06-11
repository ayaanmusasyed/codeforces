#include <bits/stdc++.h>
using namespace std; 

void solve() { 
    int n; cin >> n; 
    vector<int> a(n); 
    for (int i = 0; i < n; i++) { 
        cin >> a[i];
    }

    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        int f = 0; 
        int g = 0;  
        for (int j = i + 1; j < n; j++) { 
            if (a[j] > a[i]) { 
                f += 1;
            } else if (a[j] < a[i]) { 
                g += 1;
            }
        }

        ans[i] = max(f,g);
    } 

    for (int i = 0; i < n; i++) { 
        cout << ans[i] << " ";
    }
    cout << "\n";
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