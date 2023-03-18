#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
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
	vector<int> dp(n + 1, -1);
	function<int(int)> dfs = [&](int src){
		if (dp[src] != -1) return dp[src];
		dp[src] = src == n;
		for (int v : adj[src])
			dp[src] = (dp[src] + dfs(v)) % mod;
		return dp[src];
	};
	cout << dfs(1) << '\n';
}
	




