#include <bits/stdc++.h>
using namespace std; 


int pmex(int l, int r, int n, vector<int>& a) { 
    set<int> p; 
    for (int i = 0; i <= n; i++) { 
        p.insert(i);
    }

    while (l >= 0 && r < 2*n && a[l] == a[r]) { 
        p.erase(a[l]);
        l -= 1; 
        r += 1;
    }

    return *p.begin();
}



void solve() { 
    int n; cin >> n; 
    vector<int> a(2*n); 
    int x = -1; 
    int y = -1; 
    for (int i = 0; i < 2*n; i++) { 
        cin >> a[i];
        if (a[i] == 0) { 
            if (x > -1) { 
                y = i;
            } else { 
                x = i;
            }
        }
    }

    // idea is to center our candidate centers of arrays at the 2 0s, or the 2 0s are in the array 
    cout << max({pmex(x,x,n,a), pmex(y,y,n,a), pmex((x + y)/2,(x + y + 1)/2,n,a)}) << "\n";
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