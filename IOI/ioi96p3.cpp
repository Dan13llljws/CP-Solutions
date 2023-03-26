#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, MM = 105;
int n, t, c1, c2, scc, top, st[MM], p[MM], low[MM], in[MM], ind[MM], outd[MM]; bool inst[MM]; vector<int> adj[MM];
void dfs(int src, int par){
	low[src] = in[src] = ++t, st[++top] = src, inst[src] = 1;
	for (int v : adj[src]){
		if (v == par) continue;
		if (!in[v]) dfs(v, src), low[src] = min(low[src], low[v]);
		else if (inst[v]) low[src] = min(low[src], in[v]);
	}
	if (low[src] == in[src]){
		scc++;
		while(1){
			int v = st[top--]; p[v] = scc, inst[v] = 0;
			if (v == src) break;
		} 
	}
}
int main(){
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i++)
		while(scanf("%d", &x), x) 
			adj[i].push_back(x);
	for (int i = 1; i <= n; i++)
		if (!in[i]) dfs(i, 0);
	for (int i = 1; i <= n; i++)
		for (int v : adj[i])
			if (p[i] != p[v]) outd[p[i]]++, ind[p[v]]++;
	for (int i = 1; i <= scc; i++) 
		c1 += !ind[i], c2 += !outd[i];
	if (scc == 1) printf("1\n0\n");
	else printf("%d\n%d\n", c1, max(c1, c2));
}

