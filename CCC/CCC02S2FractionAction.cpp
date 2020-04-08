#include <bits/stdc++.h>
using namespace std;
int a, b;
int main() {
    cin >> a >> b;
    if (a == 0) cout << 0;
    else if (a % b == 0) cout << a / b;
    else {
        int q = a / b;
        a %= b;
        int x = max(a, b);
        for (int i = 2; i < x; i++){
            if(a % i == 0 && b % i == 0){
                a /= i;
                b /= i;
            }
        }
        if (q != 0) cout << q << " ";
        cout << a << "/" << b;
    }
    return 0;
}