#include <bits/stdc++.h>
using namespace std; 

void solve() { 
    int n; int k; cin >> n >> k; 
    vector<int> A(n); 

    for (auto &a : A) { 
        cin >> a; 
    }

    vector<int> P(n + 2); 
    map<int, int> F; 
    for (auto &a: A) { 
        if (F.find(a) == F.end()) { 
            F[a] = 1; 
            P[1] += 1;
        } else { 
            F[a] += 1; 
            P[F[a]] += 1;
        }
    }

    int N = n; 
    int ans = 0; 
    for (int q = 1; q <= n && P[q] != 0; q++) { 
        int p = P[q];
        if (P[q] != P[q + 1]) { 
            if (N <= k && (k - N) % p == 0) { 
                ans += 1;
            }
        }

        N -= p;
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