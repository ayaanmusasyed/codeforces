#include <bits/stdc++.h>
using namespace std; 

void solve() { 
    int mod = 676767677; 
    int n; 
    cin >> n; 
    vector<int> arr(n, 0); 
    for (int i = 0; i < n; i++) { 
        cin >> arr[i];
    }

    long long cost = 0LL; 
    // idea is that optimal removal is sum of all x > 1 in arr (+1 to cost if 1 comes after m)
    for (int i = 0; i < n; i++) { 
        if (arr[i] > 1) { 
            cost += arr[i];
        }
    }

    // check if last element is 1
    if (arr[n - 1] == 1) { 
        cost += 1;
    }

    cout << cost << "\n";
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
