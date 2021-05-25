#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 3e5 + 5;
int n, m, ans, cnt, c[MM], d[MM], dep[MM], dsu[2*MM], hvy[MM], fa[MM], head[MM]; vector<int> adj[MM]; 
int dfs(int src){
	int ret = 1, cur, mx = 0;
	for (int v : adj[src]){
		if (v == fa[src]) continue;
		fa[v] = src, ret += cur = dfs(v);
		if (cur > mx) mx = cur, hvy[src] = v;
	}
	return ret;
}
void hld(int src, int h){
	head[src] = h, dep[src] = dep[fa[src]] + 1;
	if (hvy[src]) hld(hvy[src], h);
	for (int v : adj[src])
		if (v != fa[src] && v != hvy[src]) hld(v, v);
}
int lca(int u, int v){
	for (; head[u] != head[v]; u = fa[head[u]])
		if (dep[head[u]] < dep[head[v]]) swap(u, v);
	return dep[u] < dep[v] ? u : v;
}
int Find(int x){return dsu[x] == x ? x : dsu[x] = Find(dsu[x]);}
void merge(int x, int y){
	while(dep[fa[x]] > dep[y]){
		dsu[Find(x)] = Find(fa[x]);
		dsu[Find(x + n)] = Find(fa[x] + n);
		x = Find(fa[x]);
	}
}
int main(){
	n = re, m = re;
	for (int i = 2; i <= 2 * n; i++) dsu[i] = i;
	for (int i = 1; i < n; i++){
		int a = re, b = re;
		adj[a].push_back(b), adj[b].push_back(a);
	}
	dfs(1); hld(1, 1);
	for (int i = 0; i < m; i++){
		c[i] = re, d[i] = re;
		int l = lca(c[i], d[i]);
		merge(c[i], l), merge(d[i], l);
	}
	for (int i = 0; i < m; i++){
		int l = lca(c[i], d[i]);
		if (c[i] == l || d[i] == l) continue;
		dsu[Find(c[i] + n)] = Find(d[i]);
		dsu[Find(d[i] + n)] = Find(c[i]);
	}
	for (int i = 2; i <= n; i++){
		if (Find(i) == Find(i + n)) return 0 * puts("0");
		cnt += (Find(i) == i) + (Find(i + n) == i + n);
	}
	ans = 1, cnt /= 2;
	while(cnt--) ans = ans * 2 % mod;
	printf("%d\n", ans);
}
