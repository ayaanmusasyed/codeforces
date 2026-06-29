#include <bits/stdc++.h>
using namespace std; 
using ll = long long; 

void solve() { 
    // Couldn't solve on own -> got hinted by editorial 
    /**
     * Idea is nunber of 1s either +2 or -2 -> a string is only beautiful if f(t) is not 0 mod 3 
     * 
     * Then, we remove the alternating strings as they cannot be operated on.
    */

    ll n; cin >> n; 
    string s; cin >> s; 
    ll ans = 0LL; 
    ll x = 0LL; 
    vector<ll> a(3); 
    a[0] = 1;
    char prev = ' ';
    ll y = 0; 

    for (int i = 0; i < n; i++) { 
        if (s[i] == '0') { 
            x -= 1;
        } else { 
            x += 1;
        }

        if (x < 0) { 
            x += 3;
        }
        x = x % 3; 

        if (s[i] == prev) { 
            y = 1;
        } else { 
            y += 1;
        }

        prev = s[i]; 
        ans += a[0] + a[1] + a[2] - a[x]; 
        a[x] += 1; 
        ans -= (y - 1)/2;
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