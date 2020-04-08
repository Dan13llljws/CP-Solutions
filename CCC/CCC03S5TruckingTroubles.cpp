#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define nl '\n'
typedef pair<int, int> pii;
int c, r, d, dist[100001], diset[100001], ans = INF; bool vis[100001];
vector<pair<pii, int>> edge; vector<int> dest; vector<pii> adj[100001];
bool cmp(pair<pii, int> a, pair<pii, int> b){
    return a.s > b.s;
}
int Find(int x){
    return diset[x] == x ? x : diset[x] = Find(diset[x]);
}
void unite(int x, int y){
    diset[Find(x)] = Find(y);
}
void dfs(int src){
    vis[src] = 1;
    for (int i = 0; i < sz(adj[src]); i++){
        int u = adj[src][i].s, v = adj[src][i].f;
        if (!vis[u]){
            dist[u] = v;
            dfs(u);
        }
    }
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> c >> r >> d;
    for (int i = 0, x, y, w; i < r; i++){
        cin >> x >> y >> w;
        edge.pb(mp(mp(x, y), w));
    }
    for (int i = 1; i <= c; i++) diset[i] = i;
    sort(af(edge), cmp);
    for (int i = 0, x; i < d; i++){
        cin >> x;
        dest.pb(x);
    }
    for (int i = 0; i < r; i++){
        int u = edge[i].f.f, v = edge[i].f.s, w = edge[i].s;
        if (Find(u) != Find(v)){
            unite(u, v);
            adj[u].pb(mp(w, v)); adj[v].pb(mp(w, u));
        }
    }
    dfs(1);
    for (int i = 0; i < d; i++) ans = min(ans, dist[dest[i]]);
    cout << ans;
    return 0;
}