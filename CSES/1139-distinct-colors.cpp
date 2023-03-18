#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
int n, t;
vector<int> in(MM), dep(MM), psa(MM);
vector<vector<int>> adj(MM), col(MM), anc(MM, vector<int>(20));
void dfs(int src, int par){
	in[src] = ++t, dep[src] = dep[par] + 1;
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
	cin >> n;
	vector<int> c(n + 1), comp;
	for (int i = 1; i <= n; i++)
		cin >> c[i], comp.push_back(c[i]);
	sort(comp.begin(), comp.end());
	comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
	for (int i = 1; i <= n; i++){
		c[i] = lower_bound(comp.begin(), comp.end(), c[i]) - comp.begin();
		col[c[i]].push_back(i);
	}
	for (int i = 1, a, b; i < n; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) psa[i] = 1;
	for (int i = 0; i < (int)comp.size(); i++){
		sort(col[i].begin(), col[i].end(), [](const int& a, const int& b){
			return in[a] < in[b];
		});
		for (int j = 0; j < (int)col[i].size() - 1; j++)
			psa[lca(col[i][j], col[i][j + 1])]--;
	}
	dfs1(1, 0);
	for (int i = 1; i <= n; i++) 
		cout << psa[i] << ' ';
}
