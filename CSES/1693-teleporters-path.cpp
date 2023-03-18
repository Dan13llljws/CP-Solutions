#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	vector<int> in(n + 1), out(n + 1);
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		in[b]++, out[a]++;
	}
	for (int i = 1; i <= n; i++){
		if ((i == 1 && in[i] != out[i] - 1) || (i == n && in[i] - 1 != out[i]) || (i ^ 1 && i ^ n && in[i] != out[i])){
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}
	vector<int> ans;
	function<void(int)> dfs = [&](int src){
		while(adj[src].size()){
			int v = adj[src].back();
			adj[src].pop_back();
			dfs(v);
			ans.push_back(v);
		}
	};
	dfs(1);
	if ((int)ans.size() != m){
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	reverse(ans.begin(), ans.end());
	cout << 1 << ' ';
	for (int x : ans) cout << x << ' ';
}
