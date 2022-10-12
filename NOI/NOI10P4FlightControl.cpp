#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 2005;
int n, m, vis[MM], a[MM], dp[MM], in[MM], ord[MM]; vector<int> adj[MM]; priority_queue<pair<int,int>> q;
int dfs(int src){
    if (vis[src]) return a[src];
    vis[src] = 1;
    for (int v : adj[src]) a[src] = min(a[src], dfs(v) - 1);
    return a[src];
}
int dfs1(int src){
    if (dp[src] != -1) return dp[src];
    dp[src] = 0;
    for (int v : adj[src]) dp[src] |= dfs1(v);
    return dp[src];
}
int main(){
    n = re, m = re;
    for (int i = 1; i <= n; i++) a[i] = re, ord[i] = i;
    for (int i = 0; i < m; i++){
        int u = re, v = re;
        adj[u].push_back(v), in[v]++;
    }
    for (int i = 1; i <= n; i++) dfs(i);
    for (int i = 1; i <= n; i++)
        if (!in[i]) q.push({-a[i], i});
    while(q.size()){
        int u = q.top().second; q.pop();
        printf("%d ", u);
        for (int v : adj[u])
            if (!--in[v]) q.push({-a[v], v});
    } puts("");
    sort(ord + 1, ord + 1 + n, [&](int x, int y){return a[x] > a[y];});
    for (int i = 1; i <= n; i++){
        memset(dp, -1, sizeof dp); dp[i] = 1;
        for (int j = 1; j <= n; j++) dfs1(j);
        int ans = n;
        for (int j = 1; j <= n; j++)
            if (!dp[ord[j]] && a[ord[j]] >= ans) ans--;
        printf("%d ", ans);
    } puts("");
}
