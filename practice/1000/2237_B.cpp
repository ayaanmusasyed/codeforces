#include <bits/stdc++.h>
using namespace std; 

void solve() { 
    int n; cin >> n; 
    vector<int> a(n); 
    for (int i = 0; i < n; i++) { 
        cin >> a[i];
    }

    vector<int> b(n); 
    for (int i = 0; i < n; i++) { 
        cin >> b[i];
    }

    /**
     * List is basically sorted by bubble sort -> calculate number of inversions 
     * 
     * Without doing any type I operations, the bubble sort number is an upper bound of the answer 
     * 
     * Try a greedy algorithm where we take the leftmost possible a_i to increase it to b_i
    */

    set<int> s; 
    vector<int> c(n); 
    for (int i = 0; i < n; i++) { 
        s.insert(b[i]);
    }

    bool possible = true; 
    for (int i = 0; i < n; i++) { 
        auto it = s.lower_bound(a[i]); // find the smallest element geq a[i] -> increase this to b[i]
        if (it == s.end()) {
            possible = false; 
            break; 
        }
        else { 
            c[i] = *it; 
            s.erase(it);
        }
    }

    if (!possible) { 
        cout << -1 << "\n";
    } else { 
        int ans = 0;
        for (int i = 0; i < n; i++) { 
            for (int j = i + 1; j < n; j++) { 
                if (c[i] > c[j]) { 
                    ans += 1;
                }
            }
        }

        cout << ans << "\n";
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