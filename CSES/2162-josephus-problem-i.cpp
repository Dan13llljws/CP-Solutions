#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> nxt(n);
    for (int i = 0; i < n; i++) nxt[i] = (i + 1) % n;
    for (int i = 0, j = 0; i < n; i++){
        cout << nxt[j] + 1 << ' ';
        nxt[j] = nxt[nxt[j]];
        j = nxt[j];
    }
    cout << '\n';
}

