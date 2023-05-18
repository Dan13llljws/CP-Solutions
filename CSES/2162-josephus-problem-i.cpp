#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> nxt(n), done(n);
    for (int i = 0; i < n - 1; i++) nxt[i] = i + 1;
    nxt[n - 1] = 0;
    for (int i = 0, j = 0; i < n; i++){
        cout << nxt[j] + 1 << ' ';
        nxt[j] = nxt[nxt[j]];
        done[j] = 1;
        j = nxt[j];
    }
    cout << '\n';
}

