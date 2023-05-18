#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    struct P{
        int l, r, id;
    };
    vector<P> p(n);
    vector<int> c;
    for (int i = 0; i < n; i++){
        cin >> p[i].l >> p[i].r, p[i].id = i;
        c.push_back(p[i].r);
    }
    sort(c.begin(), c.end());
    c.resize(unique(c.begin(), c.end()) - c.begin());
    vector<int> bit(n + 1);
    auto upd = [&](int x){
        for (x++; x <= n; x += x & -x) bit[x]++;
    };
    auto get = [&](int x){
        int ret = 0;
        for (x++; x; x -= x & -x) ret += bit[x];
        return ret;
    };
    auto ind = [&](int x){
        return lower_bound(c.begin(), c.end(), x) - c.begin();
    };
    sort(p.begin(), p.end(), [&](auto x, auto y){
        return x.l == y.l ? x.r > y.r : x.l < y.l;
    });
    for (int i = 0; i < n; i++){
        int j = ind(p[i].r);
        b[p[i].id] = i - get(j - 1), upd(j);
    }
    fill(bit.begin(), bit.end(), 0);
    for (int i = n - 1; i >= 0; i--){
        int j = ind(p[i].r);
        a[p[i].id] = get(j), upd(j);
    }
    for (int x : a) cout << x << ' ';
    cout << '\n';
    for (int x : b) cout << x << ' ';
    cout << '\n';
}
