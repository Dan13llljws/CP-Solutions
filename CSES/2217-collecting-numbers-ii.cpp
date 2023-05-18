#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), pos(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i], pos[a[i]] = i;
    int ans = 1;
    for (int i = 2; i <= n; i++)
        if (pos[i] < pos[i - 1]) ans++;
    while(m--){
        int i, j;
        cin >> i >> j;
        i--, j--;
        int x = a[i], y = a[j];
        if (x > y) swap(x, y);
        if (x > 1) ans -= pos[x] < pos[x - 1];
        if (y > 1) ans -= pos[y] < pos[y - 1];
        if (x < n && x < y - 1) ans -= pos[x] > pos[x + 1];
        if (y < n) ans -= pos[y] > pos[y + 1];
        swap(a[i], a[j]);
        swap(pos[x], pos[y]);
        if (x > 1) ans += pos[x] < pos[x - 1];
        if (y > 1) ans += pos[y] < pos[y - 1];
        if (x < n && x < y - 1) ans += pos[x] > pos[x + 1];
        if (y < n) ans += pos[y] > pos[y + 1];
        cout << ans << '\n';
    }
}

