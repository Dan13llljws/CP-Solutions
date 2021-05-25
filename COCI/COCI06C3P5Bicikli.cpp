#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
const int mod = 1e9, MM = 1e4 + 5; 
int n, m, dp[MM]; bool vis[MM], over;
vector<int> adj[MM];
int dfs(int src){
	if (dp[src] != -1) return dp[src];
	dp[src] = 0, vis[src] = 1;
	bool cycle = 0;
	for (int v : adj[src]){
		if (vis[v]){cycle = 1; continue;}
		dp[src] += dfs(v);
		if (dp[src] > mod) over = 1;
		dp[src] %= mod;
	}
	if (cycle && dp[src]){puts("inf"); exit(0);}
	vis[src] = 0;
	return dp[src];
}
int main(){
	n = re, m = re; ms(dp, -1); dp[2] = 1;
	for (int i = 0; i < m; i++) adj[re].pb(re);
	dfs(1);
	if (over) printf("%09d", dp[1]);
	else printf("%d", dp[1]);
}

