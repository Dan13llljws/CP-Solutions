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
    for (int i = 0; i < n; i++) cin >> p[i].l >> p[i].r, p[i].id = i;
    sort(p.begin(), p.end(), [&](auto x, auto y){
        return x.l == y.l ? x.r > y.r : x.l < y.l;
    });
    int mx = -1;
    for (int i = 0; i < n; i++){
        b[p[i].id] = mx >= p[i].r;
        mx = max(mx, p[i].r);
    }
    int mn = 2e9;
    for (int i = n - 1; i >= 0; i--){
        a[p[i].id] = mn <= p[i].r;
        mn = min(mn, p[i].r);
    }
    for (int x : a) cout << x << ' ';
    cout << '\n';
    for (int x : b) cout << x << ' ';
    cout << '\n';
}
