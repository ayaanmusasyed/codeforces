#include <bits/stdc++.h>
using namespace std; 

void solve() { 
    int n; cin >> n; 
    string t; cin >> t; 
    string b; cin >> b; 

    // idea: do dp: dp[i] is the min ops for the first i cols -> check dp[i - 1] and dp[i - 2]
    vector<int> dp(n + 1); 

    // dp[0] = 0
    if (t[0] != b[0]) { 
        dp[1] = 1;
    }

    for (int i = 2; i < n + 1; i++) { 
        // 1) add one vertical column 
        int x = dp[i - 1];
        if (t[i - 1] != b[i - 1]) { 
            x += 1;
        }

        // 2) add two horizontal rows 
        int y = dp[i - 2] + (t[i - 2] != t[i - 1]) + (b[i - 2] != b[i - 1]);

        dp[i] = min(x, y);
    }

    cout << dp[n] << "\n";
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