#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5 + 5;
int n, tot, w[MM], cnt[MM]; char s[20]; ll ans = 1e18, dp[MM]; vector<int> adj[MM];
void dfs(int src){
	for (int v : adj[src])
		dfs(v), cnt[src] += cnt[v], dp[src] += dp[v] + 1LL * cnt[v] * (w[v] + 1);
}
void dfs1(int src, ll dp1){
	if (adj[src].size()) ans = min(ans, dp1 + dp[src]);
	for (int v : adj[src])
		dfs1(v, dp1 + dp[src] - dp[v] - 1LL * cnt[v] * (w[v] + 1) + (tot - cnt[v]) * 3LL);
}
int main(){
	//freopen("dirtraverse.in", "r", stdin); freopen("dirtraverse.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1, m; i <= n; i++){
		scanf("%s %d", s, &m), w[i] = strlen(s), adj[i].resize(m);
		for (int &x : adj[i]) scanf("%d", &x);
		if (!m) dp[i] = -1, cnt[i] = 1, tot++;
	}
	dfs(1); dfs1(1, 0); printf("%lld\n", ans);
}
	
		
