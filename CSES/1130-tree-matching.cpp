#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
int ans;
bool dfs(int src, int par){
	bool flag = 0;
	for (int v : adj[src]){
		if (v == par) continue;
		flag |= dfs(v, src);
	}
	if (flag) return !++ans;
	return 1;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	adj.resize(n + 1);
	for (int i = 1, a, b; i < n; i++){
		cin >> a >> b;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	dfs(1, 0);
	cout << ans << '\n';
}
