#include <bits/stdc++.h>
using namespace std; 

void solve() { 
    int a; int b; int x; cin >> a >> b >> x; 

    // idea is maximum is |a - b| 
    int ans = abs(a - b); 

    // then, we divide the lareger one by x and compare abs 
    int d = 0;
    while (a != b) { 
        if (a > b) { 
            a = a / x;
            d += 1;
        } else if (b > a) { 
            b = b / x; 
            d += 1;
        } else { 
            break;
        }

        ans = min(ans,d + abs(a - b));
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