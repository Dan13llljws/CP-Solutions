#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
int n;
vector<int> dep(MM);
vector<vector<int>> adj(MM), anc(MM, vector<int>(20));
void dfs(int src, int par){
	dep[src] = dep[par] + 1;
	anc[src][0] = par;
	for (int i = 1; i <= ceil(log2(n)); i++)
		anc[src][i] = anc[anc[src][i - 1]][i - 1];
	for (int v : adj[src])
		dfs(v, src);
}
int lca(int u, int v){
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = ceil(log2(n)); i >= 0; i--)
		if (dep[u] - (1 << i) >= dep[v]) 
			u = anc[u][i];
	if (u == v) return u;
	for (int i = ceil(log2(n)); i >= 0; i--)
		if (anc[u][i] != anc[v][i])
			u = anc[u][i], v = anc[v][i];
	return anc[u][0];
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q;
	cin >> n >> q;
	for (int i = 2, x; i <= n; i++){
		cin >> x;
		adj[x].push_back(i);
	}
	dfs(1, 0);
	while(q--){
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << '\n';
	}
}
