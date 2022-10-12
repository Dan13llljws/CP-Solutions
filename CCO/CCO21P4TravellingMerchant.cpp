#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int mod = 1e9 + 7, MM = 2e5 + 5;
struct edge{int a, b, r, p;}e[MM<<1];
int n, m, ans[MM], out[MM], vis[MM], use[MM]; vector<int> adj[MM], rev[MM]; queue<int> qq; priority_queue<pii> q;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++){
        scanf("%d%d%d%d", &e[i].a, &e[i].b, &e[i].r, &e[i].p);
        adj[e[i].a].push_back(i), rev[e[i].b].push_back(i), out[e[i].a]++;
    }
    for (int i = 1; i <= n; i++)
        if (!out[i]) vis[i] = 1, qq.push(i);
    while(qq.size()){
        int u = qq.front(); qq.pop();
        ans[u] = -1;
        for (int v : rev[u])
            if (!--out[e[v].a])
                vis[e[v].a] = 1, qq.push(e[v].a);
    }
    for (int i = 1; i <= n; i++){
        if (vis[i]) continue;
        for (int v : adj[i])
            if (!vis[e[v].b]) q.push({e[v].r, v});
    }
    while(q.size()){
        int ed = q.top().second; q.pop();
        if (use[ed]) continue;
        use[ed] = 1;
        int a = e[ed].a, b = e[ed].b, r = e[ed].r, p = e[ed].p;
        if (!--out[a]){
            ans[a] = r;
            for (int v : rev[a]){
                if (vis[e[v].a]) continue;
                e[v].r = max(e[v].r, ans[a] - e[v].p), q.push({e[v].r, v});
            }
        }
    }
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], i == n ? '\n' : ' ');
}

