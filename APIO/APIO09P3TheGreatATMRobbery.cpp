#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 5e5 + 5;
struct edge{int to, nxt;} edges[MM], edgesr[MM], edgesc[MM];
int n, m, k, s, t, cnt, ans, comp[MM], ord[MM], val[MM], w[MM], d[MM], head[MM], headr[MM], headc[MM]; bool vis[MM];
void dfs1(int src){
	vis[src] = 1;
	for (int i = head[src]; i; i = edges[i].nxt)
		if (!vis[edges[i].to]) dfs1(edges[i].to);
	ord[t++] = src;
}
void dfs2(int src){
	comp[src] = t, w[t] += val[src];
	for (int i = headr[src]; i; i = edgesr[i].nxt){
		int v = edgesr[i].to;
		if (!comp[v]) dfs2(v);
		if (comp[v] != t) edgesc[++cnt] = {t, headc[comp[v]]}, headc[comp[v]] = cnt;
	}
}
int main(){
	n = re, m = re;
	for (int i = 0; i < m; i++){
		int a = re, b = re;
		edges[++cnt] = {b, head[a]}, head[a] = cnt;
		edgesr[cnt] = {a, headr[b]}, headr[b] = cnt;
	}
	for (int i = 1; i <= n; i++){
		val[i] = re;
		if (!vis[i]) dfs1(i);
	}
	cnt = t = 0;
	for (int i = 0; i < n; i++){
		int v = ord[n - 1 - i];
		if (!comp[v]) t++, dfs2(v);
	}
	s = re, k = re;
	for (int i = comp[s]; i <= t; i++){
		d[i] += w[i];
		for (int j = headc[i]; j; j = edgesc[j].nxt)
			d[edgesc[j].to] = max(d[edgesc[j].to], d[i]);
	}
	while(k--) ans = max(ans, d[comp[re]]);
	printf("%d\n", ans);
}

