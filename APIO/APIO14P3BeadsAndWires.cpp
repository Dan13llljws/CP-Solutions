#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define sz(x) (int)(x.size())
#define pb push_back
#define f first
#define s second
const int mod = 1e9 + 7, MM = 2e5 + 5;
int n, ans, dp[MM][2], dp2[MM][2]; vector<pii> adj[MM]; vector<int> pfx[MM], sfx[MM];
void dfs(int src, int par){
	dp[src][1] = -INF; int tmp = -INF;
	for (pii v : adj[src]){
		if (v.s == par) continue;
		dfs(v.s, src);
		dp[src][0] += max(dp[v.s][0], dp[v.s][1] + v.f);
		tmp = max(tmp, dp[v.s][0] + v.f - max(dp[v.s][0], dp[v.s][1] + v.f));
	}
	dp[src][1] = dp[src][0] + tmp;
	if (src != 1) for (int i = 0; i < sz(adj[src]); i++) if (adj[src][i].s == par){adj[src].erase(adj[src].begin() + i); break;}
	pfx[src].resize(sz(adj[src]) + 2), sfx[src].resize(sz(adj[src]) + 2); pfx[src][0] = sfx[src][sz(adj[src]) + 1] = -INF;
	for (int i = 1; i <= sz(adj[src]); i++){
		pii v = adj[src][i - 1];
		pfx[src][i] = max(pfx[src][i - 1], dp[v.s][0] + v.f - max(dp[v.s][0], dp[v.s][1] + v.f));
	}
	for (int i = sz(adj[src]); i; i--){
		pii v = adj[src][i - 1];
		sfx[src][i] = max(sfx[src][i + 1], dp[v.s][0] + v.f - max(dp[v.s][0], dp[v.s][1] + v.f));
	}
}
void dfs2(int src, int par){
	ans = max(ans, dp[src][0] + dp2[src][0]);
	for (int i = 0; i < sz(adj[src]); i++){
		pii v = adj[src][i];
		if (v.s == par) continue;
		dp2[v.s][0] = max(dp[src][0] - max(dp[v.s][0], dp[v.s][1] + v.f) + dp2[src][0], dp[src][0] - max(dp[v.s][0], dp[v.s][1] + v.f) + dp2[src][1] + v.f);
		dp2[v.s][0] = max(dp2[v.s][0], dp[src][0] - max(dp[v.s][0], dp[v.s][1] + v.f) + dp2[src][0] + max(pfx[src][i], sfx[src][i + 2]) + v.f);
		dp2[v.s][1] = max(-INF, dp[src][0] - max(dp[v.s][0], dp[v.s][1] + v.f) + dp2[src][0] + v.f);
		dfs2(v.s, src);
	}
}
int main(){
	n = re;
	for (int i = 1; i < n; i++){
		int a = re, b = re, w = re; 
		adj[a].pb({w, b}), adj[b].pb({w, a});
	}
	for (int i = 1; i <= n; i++) dp[i][1] = dp2[i][1] = -INF;
	dfs(1, 1); dfs2(1, 1);
	printf("%d", ans);
}
