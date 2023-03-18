#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> k(n + 1);
	for (int i = 1; i <= n; i++) cin >> k[i];
	vector<vector<int>> adj(n + 1), rev(n + 1);
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		rev[b].push_back(a);
	}
	vector<int> ord, vis(n + 1), p(n + 1);
	function<void(int)> dfs = [&](int src){
		vis[src] = 1;
		for (int v : adj[src])
			if (!vis[v]) dfs(v);
		ord.push_back(src);
	};
	for (int i = 1; i <= n; i++)
		if (!vis[i]) dfs(i);
	vector<ll> w(ord.size() + 1);
	vector<vector<int>> adj1(ord.size() + 1);
	int t = 0;
	function<void(int)> dfs1 = [&](int src){
		p[src] = t, w[t] += k[src];
		for (int v : rev[src])
			if (!p[v]) dfs1(v);
			else if (p[v] != t) adj1[p[v]].push_back(t);
	};
	reverse(ord.begin(), ord.end());
	for (int x : ord)
		if (!p[x]) t++, dfs1(x);
	vector<ll> dp(t + 1);
	for (int i = 1; i <= t; i++){
		dp[i] += w[i];
		for (int v : adj1[i]) dp[v] = max(dp[v], dp[i]);
	}
	ll ans = 0;
	for (int i = 1; i <= t; i++) ans = max(ans, dp[i]);
	cout << ans << '\n';
}
		
