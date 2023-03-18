#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int,int>>> adj(n + 1);
	vector<int> vis(m);
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back({b, i});
		adj[b].push_back({a, i});
	}
	for (int i = 1; i <= n; i++)
		if (adj[i].size() & 1){
			cout << "IMPOSSIBLE\n";
			return 0;
		
		}
	vector<int> ans = {1};
	function<void(int)> dfs = [&](int src){
		while(adj[src].size()){
			auto v = adj[src].back();
			adj[src].pop_back();
			if (vis[v.second]) continue;
			vis[v.second] = 1;
			dfs(v.first);
			ans.push_back(src);
		}
	};
	dfs(1);
	if ((int)ans.size() != m + 1){
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	for (int x : ans) cout << x << ' ';
}

