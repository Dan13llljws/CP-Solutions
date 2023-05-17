#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
int n, k1, k2, bid, w[MM], vis[MM], bit[MM], id[MM], cnt[MM]; long long ans; vector<int> adj[MM];
void upd(int x, int v){
    for (; x <= n; x += x & -x){
        if (id[x] != bid) id[x] = bid, bit[x] = 0;
        bit[x] += v;
    }
}
int get(int x){
    int ret = 0;
    for (; x; x -= x & -x){
        if (id[x] != bid) id[x] = bid, bit[x] = 0;
        ret += bit[x];
    }
    return ret;
}
int get_w(int src, int par){
    w[src] = 1;
    for (int v : adj[src])
        if (v != par && !vis[v]) 
            w[src]+= get_w(v, src);
    return w[src];
}
int get_cent(int src, int par, int wt){
    for (int v : adj[src])
        if (v != par && !vis[v] && (w[v] << 1) > wt)
            return get_cent(v, src, wt);
    return src;
}
void dfs(int src, int par, int d){
    if (d > k2) return;
    if (d <= k2 && d >= k1) ans++;
    ans += get(k2 - d) - get(max(0, k1 - d - 1));
    cnt[d]++;
    for (int v : adj[src])
        if (!vis[v] && v != par) dfs(v, src, d + 1);
}
void get_ans(int src){
    for (int v : adj[src]){
        if (vis[v]) continue;
        dfs(v, src, 1);
        for (int i = 1; cnt[i]; i++) upd(i, cnt[i]), cnt[i] = 0;
    }
    bid++;
}
void decomp(int src){
    get_ans(src);
    vis[src] = 1;
    for (int v : adj[src])
        if (!vis[v]) decomp(get_cent(v, v, get_w(v, v)));
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k1 >> k2;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    decomp(get_cent(1, 1, get_w(1, 1)));
    cout << ans << '\n';
}
