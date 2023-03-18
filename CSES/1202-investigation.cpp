#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5, MOD = 1e9 + 7;
int n, m, cnt[MM], mx[MM], mn[MM]; long long d[MM]; vector<pair<int,int>> adj[MM];
priority_queue<pair<long long,int>> q;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back({c, b});
    }
    memset(d, 0x3f, sizeof d);
    d[1] = 0, cnt[1] = 1, mx[1] = mn[1] = 0;
    q.push({0, 1});
    while(q.size()){
        int u = q.top().second; long long dis = -q.top().first; q.pop();
        if (dis > d[u]) continue;
        for (auto [w, v] : adj[u]){
            if (d[v] > d[u] + w){
                d[v] = d[u] + w;
                cnt[v] = cnt[u];
                mx[v] = mx[u] + 1;
                mn[v] = mn[u] + 1;
                q.push({-d[v], v});
            } else if (d[v] == d[u] + w){
                cnt[v] = (cnt[v] + cnt[u]) % MOD;
                mx[v] = max(mx[v], mx[u] + 1);
                mn[v] = min(mn[v], mn[u] + 1);
            }
        }
    }
    printf("%lld %d %d %d\n", d[n], cnt[n], mn[n], mx[n]);
}

