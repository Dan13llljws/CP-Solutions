#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 2e5 + 5;
struct edge{int to, c1, c2, nxt;} edges[MM<<1];
int n, tot, head[MM], dep[MM], psa[MM], anc[MM][20]; ll ans;
void dfs(int src, int par){
	dep[src] = dep[par] + 1;
	anc[src][0] = par;
	for (int i = 1; i <= ceil(log2(n)); i++) anc[src][i] = anc[anc[src][i - 1]][i - 1];
	for (int i = head[src]; i; i = edges[i].nxt)
		if (edges[i].to != par) dfs(edges[i].to, src);
}
int lca(int u, int v){
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = ceil(log2(n)); i >= 0; i--)
		if (dep[u] - (1 << i) >= dep[v]) u = anc[u][i];
	if (u == v) return u;
	for (int i = ceil(log2(n)); i >= 0; i--)
		if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
	return anc[u][0];
}
void dfs2(int src){
	for (int i = head[src]; i; i = edges[i].nxt){
		int v = edges[i].to;
		if (v == anc[src][0]) continue;
		dfs2(v); ans += min(1LL * edges[i].c2, 1LL * edges[i].c1 * psa[v]), psa[src] += psa[v];
	}
}
int main(){
	n = re;
	for (int i = 1; i < n; i++){
		int a = re, b = re, c1 = re, c2 = re;
		edges[++tot] = {b, c1, c2, head[a]}; head[a] = tot;
		edges[++tot] = {a, c1, c2, head[b]}; head[b] = tot;
	}
	dfs(1, 0); 
	for (int i = 2; i <= n; i++) psa[i - 1]++, psa[i]++, psa[lca(i, i - 1)] -= 2;
	dfs2(1);
	printf("%lld", ans);
}

