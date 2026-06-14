#include <bits/stdc++.h>
using namespace std; 

void solve() { 
    int n; cin >> n; 
    vector<int> A; 
    vector<int> B;
    vector<int> C; 
    vector<int> D; 
    // idea is we make array as {A | B | D | C}, where A is all ints divisible by 6, B is divisible by 2, C is 3 and D is none 

    int w;
    for (int i = 0; i < n; i++) { 
        cin >> w; 
        if (w % 6 == 0) { 
            A.push_back(w);
        } 
        else { 
            if (w % 2 == 0) { 
                B.push_back(w);
            }
            else if (w % 3 == 0) { 
                C.push_back(w);
            }
            else { 
                D.push_back(w);
            }
        }
    }
    vector<int> res;
    res.insert(res.end(), A.begin(), A.end());
    res.insert(res.end(), B.begin(), B.end());
    res.insert(res.end(), D.begin(), D.end());
    res.insert(res.end(), C.begin(), C.end());    

    for (int i = 0; i < n; i++) { 
        cout << res[i] << " ";
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