#include <bits/stdc++.h>
using namespace std;
#define ms(x, y) memset(x, y, sizeof(x))
#define nl '\n'
int n, inv[7];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i < n + 1; i++) inv[i] = 1;
    for (int i = 1, x; i < n; i++){
        cin >> x;
        inv[x] *= 1 + inv[i];
    }
    cout << inv[n];
    return 0;
}