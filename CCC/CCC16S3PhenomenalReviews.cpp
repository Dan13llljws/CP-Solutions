#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define sz(x) (int)(x.size())
#define pb push_back
char _;
int n, m, far, maxd, x; bool pho[100001];
vector<int> adj[100001];
void prune(int src, int par){
    for (int v : adj[src]){
        if (v == par) continue;
        prune(v, src);
        if (pho[v]){
            if (!pho[src]) m++;
            pho[src] = 1;
        }
    }
}
void dfs(int src, int par, int d){
    if (d > maxd){
        maxd = d;
        far = src;
    }
    for (int v : adj[src]){
        if (v == par) continue;
        if (pho[v]) dfs(v, src, d + 1);
    }
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    scan(n); scan(m);
    for (int i = 0; i < m; i++){
        scan(x);
        pho[x] = 1;
    }
    for (int i = 0, a ,b; i < n - 1; i++){
        scan(a); scan(b);
        adj[a].pb(b); adj[b].pb(a);
    }
    prune(x, -1);
    dfs(x, -1, 0);
    maxd = 0;
    dfs(far, -1, 0);
    cout << 2 * (m - 1) - maxd;
    return 0;
}