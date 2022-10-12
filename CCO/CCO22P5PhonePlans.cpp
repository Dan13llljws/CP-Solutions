#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
typedef long long ll;
struct DSU{
    int n, t, dsu[MM], stu[MM], stv[MM]; set<int> cand[MM];
    DSU (){}
    DSU (int _n) : n(_n){
        for (int i = 0; i < n; i++) dsu[i] = i, cand[i].insert(i);
    }
    int find(int x){
        while(x != dsu[x]) x = dsu[x];
        return x;
    }
}g1, g2;
struct E{int a, b, l;}ea[MM], eb[MM];
int N, A, B, ans; ll K, wa, wb, wo; unordered_map<ll,int> cnt;
ll f(ll x){return x * (x - 1) / 2;}
ll hsh(ll x, ll y){return x << 32 | y;}
void upd(int x, int y, int v){
    int z = cnt[hsh(x, y)]; cnt[hsh(x, y)] += v;
    if (cnt[hsh(x, y)] == 0) cnt.erase(hsh(x, y));
    wo += f(cnt[hsh(x, y)]) - f(z);
}
void unite(int i, int x, int y){
    if (i){
        x = g2.find(x), y = g2.find(y);
        wb += 1LL * g2.cand[x].size() * g2.cand[y].size();
        if (g2.cand[x].size() > g2.cand[y].size()) swap(x, y);
        for (int v : g2.cand[x]){
            int p = g1.find(v);
            upd(p, x, -1), upd(p, y, 1), g2.cand[y].insert(v);
        } g2.dsu[x] = y, g2.stu[++g2.t] = x, g2.stv[g2.t] = y;
    } else {
        x = g1.find(x), y = g1.find(y);
        wa += 1LL * g1.cand[x].size() * g1.cand[y].size();
        if (g1.cand[x].size() > g1.cand[y].size()) swap(x, y);
        for (int v : g1.cand[x]){
            int p = g2.find(v);
            upd(x, p, -1), upd(y, p, 1), g1.cand[y].insert(v);
        } g1.dsu[x] = y;
    }
}
void roll_back(){
    int u = g2.stu[g2.t], v = g2.stv[g2.t];
    g2.t--, g2.dsu[u] = u;
    for (int x : g2.cand[u]){
        int x1 = g1.find(x);
        upd(x1, v, -1), upd(x1, u, 1), g2.cand[v].erase(x);
    } wb -= 1LL * g2.cand[u].size() * g2.cand[v].size();
}
int main(){
    scanf("%d%d%d%lld", &N, &A, &B, &K); ans = K ? 2e9 : 0;
    for (int i = 0; i < A; i++) scanf("%d%d%d", &ea[i].a, &ea[i].b, &ea[i].l);
    for (int i = 0; i < B; i++) scanf("%d%d%d", &eb[i].a, &eb[i].b, &eb[i].l);
    vector<E> gb;
    sort(ea, ea + A, [](E a, E b){return a.l < b.l;});
    sort(eb, eb + B, [](E a, E b){return a.l < b.l;});
    g1 = DSU(N + 1), g2 = DSU(N + 1);
    for (int i = 1; i <= N; i++) upd(i, i, 1);
    for (int i = 0; i < B; i++){
        int a = eb[i].a, b = eb[i].b;
        if (g2.find(a) != g2.find(b))
            unite(1, a, b), gb.push_back(eb[i]);
    } B = gb.size();
    int j = B - 1;
    while(j >= 0 && wb >= K) ans = min(ans, gb[j--].l), roll_back();
    for (int i = 0; i < A; i++){
        if (g1.find(ea[i].a) == g1.find(ea[i].b)) continue;
        unite(0, ea[i].a, ea[i].b);
        if (wa >= K){ans = min(ans, ea[i].l); break;}
        while(j >= 0 && wa + wb - wo >= K) ans = min(ans, ea[i].l + gb[j--].l), roll_back();
    } printf("%d\n", ans == 2e9 ? -1 : ans);
}
