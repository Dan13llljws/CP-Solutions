#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
const int MM = 1e5 + 5;
int n, mod, dp[MM], dp2[MM], ans[MM];
vector<int> adj[MM], pfx[MM], sfx[MM];
void dfs(int src, int par){
	int id; dp[src] = 1;
	for (int i = 0; i < (int)adj[src].size(); i++){
		int v = adj[src][i];
		if (v == par){id = i; continue;}
		dfs(v, src);
		dp[src] = 1LL * dp[src] * (1 + dp[v]) % mod;
	}
	if (src != 1) adj[src].erase(adj[src].begin() + id);
	int m = adj[src].size();
	if (!m) return;
	pfx[src].resize(m + 2), sfx[src].resize(m + 2);
	pfx[src][0] = sfx[src][m + 1] = 1;
	for (int i = 1; i <= m; i++)
		pfx[src][i] = 1LL * pfx[src][i - 1] * (1 + dp[adj[src][i - 1]]) % mod;
	for (int i = m; i; i--)
		sfx[src][i] = 1LL * sfx[src][i + 1] * (1 + dp[adj[src][i - 1]]) % mod;
}
void dfs2(int src){
	for (int i = 0; i < (int)adj[src].size(); i++){
		dp2[adj[src][i]] = (1LL * dp2[src] * pfx[src][i] % mod * sfx[src][i + 2] % mod + 1) % mod;
		dfs2(adj[src][i]);
	}
}
int main(){
	n = read(), mod = read();
	for (int i = 1; i < n; i++){
		int a = read(), b = read();
		adj[a].push_back(b), adj[b].push_back(a);
	}
	dfs(1, 1); dp2[1] = 1; dfs2(1);
	for (int i = 1; i <= n; i++) printf("%d\n", 1LL * dp[i] * dp2[i] % mod);
}
	
