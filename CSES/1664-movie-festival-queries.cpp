#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    struct E {
        int s, t;
        bool operator <(E const &o){
            return s == o.s ? t > o.t : s < o.s;
        }
    };
    vector<E> e(n), st;
    for (int i = 0; i < n; i++) cin >> e[i].s >> e[i].t;
    sort(e.begin(), e.end());
    for (int i = 0; i < n; i++){
        while(st.size() && st.back().t >= e[i].t) st.pop_back();
        st.push_back(e[i]);
    }
    n = st.size();
    st.push_back({0x3f3f3f3f, 0x3f3f3f3f});
    vector<vector<int>> f(20, vector<int>(n + 1));
    for (int i = 0, j = 1; i < n; i++){
        while(j < n && st[j].s < st[i].t) j++;
        f[0][i] = j;
    } f[0][n] = n;
    for (int i = 1; i < 20; i++)
        for (int j = 0; j <= n; j++)
            f[i][j] = f[i - 1][f[i - 1][j]];
    while(q--){
        E x;
        cin >> x.s >> x.t;
        int i = lower_bound(st.begin(), st.end(), x) - st.begin();
        if (st[i].t > x.t){
            cout << 0 << '\n';
            continue;
        }
        int ans = 1;
        for (int j = 19; j >= 0; j--)
            if (st[f[j][i]].t <= x.t) ans += 1 << j, i = f[j][i];
        cout << ans << '\n';
    }
}

