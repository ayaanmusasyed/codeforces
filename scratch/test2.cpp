#include <iostream>
using namespace std;

int main() { 
    int n; 
    int a; 
    int b; 
    
    cin >> n >> a >> b; 
    
    int x = 0; 
    int y = 0; 
    int z = 0; 
    
    int i = 1; 
    while (i <= n) { 
        if (i % a == 0 && i % b == 0) {
            z += 1; 
        } else if (i % a == 0) { 
            x += 1;
        } else if (i % b == 0) { 
            y += 1;
        }
        
        i += 1;
    }
    
    cout << x << " " << y << " " << z << "\n";
    return 0; 
}