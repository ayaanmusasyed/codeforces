#include <bits/stdc++.h>
using namespace std; 

bool can(int k, multiset<int>& ms) { 
    vector<int> removed; 

    // idea is to try to create all values 0, 1, ..., k - 1
    // we go from largest to smallest because larger x is harder to make
    for (int x = k - 1; x >= 0; x--) { 

        // if x already exists, use it directly
        auto it = ms.find(x); 
        if (it != ms.end()) { 
            removed.push_back(x);
            ms.erase(it);
        } else { 
            // otherwise, use the largest spare value
            // if the largest cannot make x, nothing else can
            int y = *ms.rbegin(); 

            if (y < 2*x + 1) { 
                // put back everything before returning
                for (int z : removed) { 
                    ms.insert(z);
                }
                return false; 
            }

            removed.push_back(y);
            ms.erase(ms.find(y));
        }
    }

    // restore multiset so binary search can reuse it
    for (int z : removed) { 
        ms.insert(z);
    }

    return true; 
}

void solve() { 
    int n; cin >> n; 
    vector<int> a(n); 
    for (int i = 0; i < n; i++) { 
        cin >> a[i]; 
    }

    // idea is for p, the only new possible values it can take after operation are {0,1,2...,floor((p - 1)/2), p}
    // the max answer for such a query is the length of the array n itself 

    // we would want to use the smallest possible number to get x, eg we wouldnt use a 8 to get to a 0 if a smaller number exists as 
    // we can use the 8 to get numbers like 3 and 8. 
    // consider using duplicates and elements larger than n - 1

    // note: prior to looking at the editorial, i did a linear one pass search -> correct idea is to use binary search to find mex 
    // use a multiset 

    // fix for TLE: build multiset once instead of rebuilding frequency/spare inside every can()
    multiset<int> ms(a.begin(), a.end());

    int l = 0; int r = n; int ans = 0; 
    while (l <= r) { 
        int m = l + (r - l)/2; 

        if (can(m, ms)) { 
            ans = m; 
            l = m + 1; 
        } else { 
            r = m - 1;
        }
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