#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
int n, k, d[MM]; vector<int> adj[MM];
int dfs(int src, int par, int dis){
	int ret = 0; d[src] = 1e9;
	if (adj[src].size() == 1) d[src] = dis;
	for (int v : adj[src])
		if (v != par) ret += dfs(v, src, dis + 1), d[src] = min(d[src], d[v]);
	if ((d[src] + 1) / 2 == dis) return 1;
	return ret;
}
int main(){
	//freopen("atlarge.in", "r", stdin); freopen("atlarge.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++){
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b); adj[b].push_back(a);
	}
	printf("%d\n", dfs(k, k, 0));
}
