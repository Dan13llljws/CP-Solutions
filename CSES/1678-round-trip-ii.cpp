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
	vector<int> vis(n + 1), par(n + 1);
	function<int(int)> dfs = [&](int src){
		vis[src] = 1;
		for (int v : adj[src]){
			if (vis[v] == 2) continue;
			par[v] = src;
			if (vis[v] == 1) return v;
			int t = dfs(v);
			if (t) return t;
		}
		vis[src] = 2;
		return 0;
	};
	int x = 0;
	for (int i = 1; i <= n; i++) 
		if (!vis[i] && !x) x = dfs(i);
	if (!x){
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	vector<int> ans;
	for (int i = x;; i = par[i]){
		ans.push_back(i);
		if (ans.size() > 1 && i == x) break;
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int v : ans) cout << v << ' ';
	cout << '\n';
}
	

