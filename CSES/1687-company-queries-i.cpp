#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
int n;
vector<int> dep(MM);
vector<vector<int>> anc(MM, vector<int>(20)), adj(MM);
void dfs(int src, int par){
	dep[src] = dep[par] + 1;
	anc[src][0] = par;
	for (int i = 1; i <= ceil(log2(n)); i++) anc[src][i] = anc[anc[src][i - 1]][i - 1];
	for (int v : adj[src])
		dfs(v, src);
}
int lift(int u, int d){
	for (int i = ceil(log2(n)); i >= 0; i--)
		if (dep[u] - (1 << i) >= d) u = anc[u][i];
	return u;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q;
	cin >> n >> q;
	for (int i = 2, v; i <= n; i++){
		cin >> v;
		adj[v].push_back(i);
	}
	dfs(1, 0);
	while(q--){
		int x, y;
		cin >> x >> y;
		int ans = lift(x, dep[x] - y);
		cout << (ans ? ans : -1) << '\n';
	}
}
