#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5 + 5;
int go[30][MM];
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> go[0][i];
    for (int i = 1; i < 30; i++)
        for (int j = 1; j <= n; j++) go[i][j] = go[i - 1][go[i - 1][j]];
    while(q--){
        int v, k;
        cin >> v >> k;
        for (int i = k ? 31 - __builtin_clz(k) : 0; i >= 0; i--)
            if ((1 << i) <= k) v = go[i][v], k -= (1 << i);
        cout << v << '\n';
    }
}
