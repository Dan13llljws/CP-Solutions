#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
int far, maxd;
void dfs(int src, int par, int d){
	if (d > maxd) maxd = d, far = src;
	for (int v : adj[src])
		if (v != par) dfs(v, src, d + 1);
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
	dfs(1, 0, 0);
	maxd = 0;
	dfs(far, 0, 0);
	cout << maxd << '\n';
}
