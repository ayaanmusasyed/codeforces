#include <bits/stdc++.h>
using namespace std; 

void solve() { 
    int n; int m; cin >> n >> m; 
    vector<int> arr(n); 
    for (int i = 0; i < n; i++) { 
        cin >> arr[i]; 
    }

    // idea if what is the longest stretch of consequtive elements, thus determining possibility if s > m or not 
    int s = 0; // longest streak 
    int p = 0; // temp streak
    int curr = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] != curr) { 
            s = max(s, p);
            p = 1;
            curr = arr[i];
        } else { 
            p += 1;
        }
    }

    s = max(s, p);

    if (s >= m) { 
        cout << "NO";
    } else { 
        cout << "YES";
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