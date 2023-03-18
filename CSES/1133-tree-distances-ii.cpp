#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
vector<vector<int>> adj(MM);
vector<int> w(MM);
vector<long long> dist(MM), ans(MM);
int n;
void dfs(int src, int par){
	w[src] = 1;
	for (int v : adj[src]){
		if (v == par) continue;
		dfs(v, src);
		w[src] += w[v];
		dist[src] += dist[v] + w[v];
	}
}
void dfs1(int src, int par, long long dp){
	ans[src] = dp + dist[src];
	for (int v : adj[src]){
		if (v == par) continue;
		dfs1(v, src, dp + dist[src] - dist[v] - w[v] + (n - w[v]));
	}
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1, a, b; i < n; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0); dfs1(1, 0, 0);
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
}
