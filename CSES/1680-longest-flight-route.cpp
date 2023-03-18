#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	vector<int> c(n + 1), dp(n + 1);
	function<int(int)> dfs = [&](int src){
		if (dp[src]) return dp[src];
		dp[src] = src == n ? 1 : -1e9;
		for (int v : adj[src]){
			int cur = dfs(v);
			if (cur + 1 > dp[src]) dp[src] = cur + 1, c[src] = v;
		}
		return dp[src];
	};
	int ans = dfs(1);
	if (ans < 0) cout << "IMPOSSIBLE\n";
	else {
		cout << ans << '\n';	
		for (int i = 1; i; i = c[i])
			cout << i << ' ';
	}
}
	



