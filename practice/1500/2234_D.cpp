#include <bits/stdc++.h>
using namespace std; 
using ll = long long; 

void solve() { 
    int n; int k; cin >> n >> k; 
    string s; cin >> s; 
    string l; cin >> l;
    string m; 
    for (int i = 0; i < n; i++) { 
        if (s[i] == l[i]) { 
            m += '0';
        } else { 
            m += '1';
        }
    }

    // (a XOR b) XOR a = b -> there are only 3 binary strings in the whole 2^k + 1 strings -> thus we just need to count score of the 3 and add 
    // and multuply by the number of times they show up -> i found the formula via construction 

    // scores 
    ll S = 0LL; 
    ll a = 0;
    ll b = 0;
    for (int i = 0; i < n; i++) { 
        if (s[i] == '0') { 
            a += 1;
        } else { 
            b += 1;
        }
    }
    S = a*b; 


    ll M = 0LL; 
    a = 0;
    b = 0;
    for (int i = 0; i < n; i++) { 
        if (m[i] == '0') { 
            a += 1;
        } else { 
            b += 1;
        }
    }
    M = a*b;

    ll L = 0LL;
    a = 0;
    b = 0;
    for (int i = 0; i < n; i++) { 
        if (l[i] == '0') { 
            a += 1;
        } else { 
            b += 1;
        }
    }
    L = a*b;

    
    ll ans = 0LL; 
    if (k == 1) { 
        ans = S + M + L;
    } else { 
        int q = 1; 
        for (int j = 2; j <= k; j++) { 
            if (q % 2 == 1) { 
                q *= 2;
            } else { 
                q = 2*q - 1;
            }
        }

        ans = q*(S + L) + ((1LL << k) + 1 - 2*q)*M;
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