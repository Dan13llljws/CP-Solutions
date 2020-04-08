#include <bits/stdc++.h>
using namespace std;
int n, a[100000], b[100000], m = 0;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    if (a[0] == b[0]) m = 1;
    for (int i = 1; i < n; i++){
        a[i] += a[i - 1];
        b[i] += b[i - 1];
        if (a[i] == b[i]) m = i + 1;
    }
    cout << m;
    return 0;
}