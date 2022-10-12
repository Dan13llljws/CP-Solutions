#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 5005;
int n, m, t, h, g, tmp[MM], ord[MM], on[MM], vis[MM]; vector<pair<int,int>> adj[MM];
void dfs(int src, int par, int blc){
    tmp[t++] = src;
    for (auto [v, i] : adj[src]) 
        if (v != par && i != blc) dfs(v, src, blc);
}
void dfs1(int src, int par){
    if (vis[src]){h = src, g = 1; return;}
    vis[src] = 1;
    for (auto [v, i] : adj[src]){
        if (v != par) dfs1(v, src);
        if (g){
            on[i] = 1, g = h != src;
            return;
        }
    }
}
int main(){
    n = re, m = re;
    for (int i = 0; i < m; i++){
        int a = re, b = re;
        adj[a].push_back({b, i}), adj[b].push_back({a, i});
    } dfs1(1, 1);
    for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
    if (m == n - 1){
        dfs(1, 1, -1);
        for (int i = 0; i < n; i++) printf("%d%c", tmp[i], i == n - 1 ? '\n' : ' ');
        return 0;
    } memset(ord, 0x3f, sizeof ord);
    for (int i = 0; i < n; i++){
        if (!on[i]) continue;
        t = 0, dfs(1, 1, i); int f = 0;
        for (int j = 0; j < n; j++){
            if (tmp[j] < ord[j]) f = 1;
            if (f){ord[j] = tmp[j]; continue;}
            if (tmp[j] > ord[j]) break;
        }
    }
    for (int i = 0; i < n; i++) printf("%d%c", ord[i], i == n - 1 ? '\n' : ' ');
}
