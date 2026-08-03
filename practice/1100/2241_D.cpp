#include <bits/stdc++.h>
using namespace std; 
using ll = long long; 

void solve() { 
    int n; cin >> n; 
    vector<ll> A(n); 
    vector<ll> B(n); 

    for (auto &a: A) { 
        cin >> a; 
    }
    for (auto &b: B) { 
        cin >> b; 
    }

    vector<ll> C(n); 
    for (int i = 0; i < n; i++) { 
        C[i] = A[i] - B[i];
    }

    // idea is sum can only increase and if maintained, we can only decrease at index k if all the ones before it have been adjusted 
    // check this by doing c = a[i] - b[i] and running prefix sum 

    int j = 0; 
    ll x = 0; // prefix sum
    while (j < n) { 
        x += C[j];

        if (x > 0) { 
            cout << "NO\n";
            return;
        }

        j += 1;
    }

    cout << "YES\n";


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