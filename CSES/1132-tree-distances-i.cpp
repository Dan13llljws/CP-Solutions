#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 +5;
vector<vector<int>> adj(MM);
vector<int> best(MM), sec(MM), ans(MM);
void update(int &a, int &b, int c){
	if (c > a) b = a, a = c;
	else if (c > b) b = c;
}
void dfs(int src, int par){
	sec[src] = -1;
	for (int v : adj[src]){
		if (v == par) continue;
		dfs(v, src);
		update(best[src], sec[src], best[v] + 1);
	}
	ans[src] = best[src];
}
void dfs1(int src, int par, int dp){
	ans[src] = max(ans[src], dp);
	for (int v : adj[src]){
		if (v == par) continue;
		if (best[src] == best[v] + 1) dfs1(v, src, max(dp + 1, sec[src] + 1));
		else dfs1(v, src, max(dp + 1, best[src] + 1));
	}
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
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
