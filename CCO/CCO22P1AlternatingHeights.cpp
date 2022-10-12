#include <bits/stdc++.h>
using namespace std;
const int MM = 3005;
int n, k, q, a[MM], can[MM], vis[MM]; deque<int> adj[MM];
int dfs(int src){
    vis[src] = 1;
    for (int v : adj[src]){
        if (vis[v] == 1) return 1;
        if (!vis[v] && dfs(v)) return 1;
    } vis[src] = 2; return 0;
}
int main(){
    scanf("%d%d%d", &n, &k, &q);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int l = 1, r = 1; l <= n; l++){
        for (; r <= n; r++){
            bool cyc = 0; memset(vis, 0, sizeof vis);
            for (int i = 1; i <= k && !cyc; i++) cyc |= dfs(i);
            if (cyc) break;
            if (r & 1) adj[a[r + 1]].push_back(a[r]);
            else adj[a[r]].push_back(a[r + 1]);
        }
        if (l & 1) adj[a[l + 1]].pop_front();
        else adj[a[l]].pop_front();
        can[l] = r;
    }
    while(q--){
        int x, y; scanf("%d%d", &x, &y);
        puts(y < can[x] ? "YES" : "NO");
    }
}

