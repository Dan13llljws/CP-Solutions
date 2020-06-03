#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define pb push_back
const int mod = 1e9 + 7, base = 131, MM = 2e5 + 5;
int n, m, x[MM], y[MM], l[MM], anc[MM][20], dep[MM], psa[MM]; ll ans;
vector<int> adj[MM]; unordered_map<ll, int> cnt;
ll hsh(int a, int b){
	if (a > b) swap(a, b);
	return 1LL * a * MM + b;
}
void dfs(int src, int par){
	dep[src] = dep[par] + 1;
	anc[src][0] = par;
	for (int i = 1; i <= ceil(log2(n)); i++) anc[src][i] = anc[anc[src][i - 1]][i - 1];
	for (int v : adj[src])
		if (v != par) dfs(v, src);
}
int lca(int u, int v){
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = ceil(log2(n)); i >= 0; i--) 
		if (dep[anc[u][i]] >= dep[v]) u = anc[u][i];
	if (u == v) return u;
	for (int i = ceil(log2(n)); i >= 0; i--)
		if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
	return anc[u][0];
}
void dfs2(int src){
	for (int v : adj[src]){
		if (v == anc[src][0]) continue;
		psa[v] += psa[src];
		dfs2(v);
	}
}
int get_top(int u, int v){
	if (u == v) return 0;
	for (int i = ceil(log2(n)); i >= 0; i--)
		if (dep[anc[v][i]] > dep[u]) v = anc[v][i];
	return v;
}
int main(){
	n = re, m = re;
	for (int i = 1; i < n; i++){
		int a = re, b = re;
		adj[a].pb(b), adj[b].pb(a);
	}
	dfs(1, 1);
	for (int i = 0; i < m - n + 1; i++){
		x[i] = re, y[i] = re, l[i] = lca(x[i], y[i]);
		int tx = get_top(l[i], x[i]), ty = get_top(l[i], y[i]); 
		if (tx) ans -= psa[tx]++ + 1; // +1 is because itself will be overcounted too
		if (ty) ans -= psa[ty]++ + 1;
		if (tx && ty) ans -= cnt[hsh(tx, ty)]++;
	}
	dfs2(1);
	for (int i = 0; i < m - n + 1; i++)
		ans += psa[x[i]] + psa[y[i]] - 2 * psa[l[i]];
	printf("%lld", ans);
}

