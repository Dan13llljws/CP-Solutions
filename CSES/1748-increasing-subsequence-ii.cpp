#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), c;
    for (int &x : a) cin >> x, c.push_back(x);
    c.push_back(0);
    sort(c.begin(), c.end()), c.resize(unique(c.begin(), c.end()) - c.begin());
    for (int i = 0; i < n; i++)
        a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin() + 1;
    int m = c.size();
    vector<int> bit(m + 1);
    auto upd = [&](int x, int v){
        for (; x <= m; x += x & -x) bit[x] = (bit[x] + v) % MOD;
    };
    auto get = [&](int x){
        int ret = 0;
        for (; x; x -= x & -x) ret = (ret + bit[x]) % MOD;
        return ret;
    };
    int ans = 0;
    upd(1, 1);
    for (int i = 0; i < n; i++){
        int cur = get(a[i] - 1);
        upd(a[i], cur), ans = (ans + cur) % MOD;
    }
    cout << ans << '\n';
}
