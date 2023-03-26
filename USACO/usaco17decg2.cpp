#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5, mod = 1e9 + 7;
int n, k, c[MM], dp[4][MM]; vector<int> adj[MM];
void dfs(int src, int par){
	for (int i = 1; i <= 3; i++)
		if (!c[src] || c[src] == i) dp[i][src] = 1;
	for (int v : adj[src]){
		if (v == par) continue;
		dfs(v, src);
		for (int i = 1; i <= 3; i++){
			int s = 0;
			for (int j = 1; j <= 3; j++)
				if (i ^ j) s = (s + dp[j][v]) % mod;
			dp[i][src] = 1LL * dp[i][src] * s % mod;
		}
	}
}
int main(){
	//freopen("barnpainting.in", "r", stdin); freopen("barnpainting.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1, a, b; i < n; i++){
		scanf("%d%d", &a, &b);
		adj[a].push_back(b); adj[b].push_back(a);
	}
	for (int i = 0, a, b; i < k; i++) scanf("%d%d", &a, &b), c[a] = b;
	dfs(1, 0); printf("%d\n", (1LL * dp[1][1] + dp[2][1] + dp[3][1]) % mod);
}
