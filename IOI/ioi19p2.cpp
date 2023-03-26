#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e5 + 5;
struct E{int u, v;}e[MM<<1], bad[MM<<1];
int N, tb, cnt, t, rt, id, sz[MM], dsu[MM], w[MM], vis[MM]; vector<int> s, adj[MM]; pair<int,int> ord[3];
int Find(int x){return dsu[x] == x ? x : dsu[x] = Find(dsu[x]);}
void unite(int x, int y){x = Find(x), y = Find(y); sz[y] += sz[x], dsu[x] = y;}
int get_w(int src, int par){
    w[src] = 1;
    for (int v : adj[src])
        if (v != par) w[src] += get_w(v, src);
    return w[src];
}
int get_c(int src, int par){
    for (int v : adj[src])
        if (v != par && w[v] * 2 > N) return get_c(v, src);
    return src;
}
void merge(int src, int par){
    if (par != rt) unite(src, par);
    for (int v : adj[src])
        if (v != par) merge(v, src);
}
void paint(int src, int f){
    if (s[src] || (!f && src == rt)) return;
    vis[src] = 1, cnt ? (s[src] = ord[f].second, cnt--) : s[src] = ord[2].second;
    for (int v : adj[src])
        if (!vis[v]) paint(v, f);
}
vector<int> find_split(int n, int a, int b, int c, vector<int>p, vector<int>q){
    int m = p.size(); s.resize(N = n);
    for (int i = 0; i < m; i++) e[i] = {q[i], p[i]};
    ord[0] = {a, 1}, ord[1] = {b, 2}, ord[2] = {c, 3};
    sort(ord, ord + 3); iota(dsu, dsu + n, 0);
    for (int i = 0; i < m; i++){
        if (Find(e[i].v) != Find(e[i].u)){
            unite(e[i].v, e[i].u);
            adj[e[i].v].push_back(e[i].u), adj[e[i].u].push_back(e[i].v);
        } else bad[tb++] = e[i];
    } get_w(0, 0), rt = get_c(0, 0), iota(dsu, dsu + n, 0);
    for (int i = 0; i < n; i++) sz[i] = 1;
    for (int v : adj[rt]) merge(v, rt);
    bool f = 0;
    for (int v : adj[rt]) 
        if (sz[Find(v)] >= ord[0].first) f = 1;
    for (int i = 0; i < tb && !f; i++){
        if (bad[i].u == rt || bad[i].v == rt) continue;
        if (sz[Find(bad[i].u)] >= ord[0].first || sz[Find(bad[i].v)] >= ord[0].first) break;
        if (Find(bad[i].u) != Find(bad[i].v)){
            int v = bad[i].v, u = bad[i].u;
            unite(u, v), adj[u].push_back(v); adj[v].push_back(u);
        }
    } id = -1;
    for (int v : adj[rt])
        if (sz[Find(v)] >= ord[0].first){id = v; break;}
    if (id != -1){
        cnt = ord[0].first, paint(id, 0), memset(vis, 0, sizeof vis);
        cnt = ord[1].first, paint(rt, 1);
    } return s;
}
// int main(){
//     freopen("in.in", "r", stdin);
//     int n, m, A, B, C;
//     cin >> n >> m >> A >> B >> C;
//     vector<int> a, b;
//     for (int i = 0; i < m; i++){
//         int x, y;
//         cin >> x >> y;
//         a.push_back(x), b.push_back(y);
//     }
//     vector<int> ans = find_split(n, A, B, C, a, b);
//     for (int i= 0; i < n; i++){
//         cout << i << ": " << ans[i] << '\n';
//         }
// }
