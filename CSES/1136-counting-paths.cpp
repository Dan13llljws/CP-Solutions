#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
int n;
vector<int> dep(MM), psa(MM);
vector<vector<int>> adj(MM), anc(MM, vector<int>(20));
void dfs(int src, int par){
	dep[src] = dep[par] + 1;
	anc[src][0] = par;
	for (int i = 1; i <= ceil(log2(n)); i++)
		anc[src][i] = anc[anc[src][i - 1]][i - 1];
	for (int v : adj[src])
		if (v != par) dfs(v, src);
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
void dfs1(int src, int par){
	for (int v : adj[src]){
		if (v == par) continue;
		dfs1(v, src);
		psa[src] += psa[v];
	}
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int m;
	cin >> n >> m;
	for (int i = 1, a, b; i < n; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);
	while(m--){
		int a, b;
		cin >> a >> b;
		int l = lca(a, b);
		psa[a]++, psa[b]++, psa[l]--, psa[anc[l][0]]--;
	}
	dfs1(1, 0);
	for (int i = 1; i <= n; i++) 
		cout << psa[i] << ' ';
}
