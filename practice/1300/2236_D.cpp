#include <bits/stdc++.h>
using namespace std; 
using ll = long long; 

void solve() { 
    /**
     * idea is if for some [x,x,x,x,..x] if count is even then P2 wins else P1
     * 
     * including k > 0, we just need to check for some z = x - k if there is at least one, then if |x| is odd, we pick x - k then 1 x and then P2 can win 
    */

    int n; int k; cin >> n >> k; 
    vector<int> a(n); 
    map<int, int> f; 

    int h = 0; 
    for (int i = 0; i < n; i++) { 
        cin >> a[i];
        f[a[i]] += 1; 
        h = max(h, a[i]);
    }

    bool egor_win = false;

   while (h > 0) { 
        if (f[h] > 0) { 
            if (f[h] % 2 == 0) { 
                egor_win = true; 
                break; 
            } else { 
                // Find the next largest element strictly less than h
                auto it = f.lower_bound(h);
                if (it != f.begin()) {
                    --it; // This points to the second maximum
                    int next_h = it->first;
                    if (h - next_h <= k) {
                        egor_win = true;  
                    }
                }
                if (egor_win) {
                    break;
                }
            }
        }
        
        // Instead of h -= k, jump directly to the next largest element
        auto it = f.lower_bound(h);
        if (it != f.begin()) {
            --it;
            h = it->first;
        } else {
            break; // No more elements left
        }
    }

    if (egor_win) { 
        cout << "YES" << "\n";
    } else { 
        cout << "NO" << "\n";
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