#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> pos(n + 1);
    for (int i = 0, x; i < n; i++) cin >> x, pos[x] = i;
    int ans = 1;
    for (int i = 2; i <= n; i++)
        if (pos[i] < pos[i - 1]) ans++;
    cout << ans << '\n';
}
