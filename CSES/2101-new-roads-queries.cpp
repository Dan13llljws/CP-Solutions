#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    int t = n;
    vector<vector<int>> fa(20, vector<int>(n + m));
    vector<int> dsu(n + m), dep(n + m);
    iota(dsu.begin(), dsu.end(), 0);
    auto find = [&](auto self, int x) -> int{
        return dsu[x] == x ? x : dsu[x] = self(self, dsu[x]);
    };
    auto unite = [&](int x, int y) -> void{
        x = find(find, x), y = find(find, y);
        if (x == y) return;
        fa[0][x] = fa[0][y] = fa[0][t] = t;
        dsu[x] = dsu[y] = t;
    };
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        unite(a, b);
        t++;
    }
    for (int i = n + m - 1; i >= 0; i--)
        dep[i] = dep[fa[0][i]] + 1;
    for (int i = 1; i < 20; i++)
        for (int j = 0; j < n + m; j++)
            fa[i][j] = fa[i - 1][fa[i - 1][j]];
    auto lca = [&](int u, int v) -> int{
        if (dep[u] < dep[v]) swap(u, v);
        for (int i = 19; i >= 0; i--)
            if (dep[u] >= dep[v] + (1 << i)) u = fa[i][u];
        if (u == v) return u;
        for (int i = 19; i >= 0; i--)
            if (fa[i][u] != fa[i][v]) u = fa[i][u], v = fa[i][v];
        return fa[0][u];
    };
    while(q--){
        int a, b;
        cin >> a >> b;
        if (a == b){
            cout << 0 << '\n';
            continue;
        }
        a--, b--;
        if (find(find, a) != find(find, b)){
            cout << -1 << '\n';
            continue;
        }
        cout << lca(a, b) - n + 1 << '\n';
    }
}
