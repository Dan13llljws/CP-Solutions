#include <bits/stdc++.h>
#include "factories.h"
using namespace std;
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
typedef long long ll;
typedef pair<int, int> pii;
#define ms(x, y) memset(x, y, sizeof(x))
const int mod = 1e9 + 7, base = 131, MM = 5e5 + 5, LG = 25;
struct edge{int v, w, nxt;}edges[MM*2];
int n, tot, dep[MM], w[MM], pre[MM], head[MM*2]; bool vis[MM];
ll dist[LG][MM], ans[MM];
vector<int> clr;
void add_edge(int u, int v, int w){edges[++tot].v = v, edges[tot].w = w, edges[tot].nxt = head[u], head[u] = tot;}
void get_weight(int src, int par){
	w[src] = 1;
	for (int i = head[src]; i; i = edges[i].nxt){
		int v = edges[i].v;
		if (v == par || vis[v]) continue;
		get_weight(v, src);
		w[src] += w[v];
	}
}
int get_cent(int src, int par, int wt){
	for (int i = head[src]; i; i = edges[i].nxt){
		int v = edges[i].v;
		if (v != par && !vis[v] && w[v] * 2 > wt)
			return get_cent(v, src, wt);
	}
	return src;
}
void dfs(int src, int par, ll d, int lvl){
	dist[lvl][src] = d;
	for (int i = head[src]; i; i = edges[i].nxt){
		int v = edges[i].v, w = edges[i].w;
		if (v == par || vis[v]) continue;
		dfs(v, src, d + w, lvl);
	}
}
void decomp(int src, int lvl){
	dfs(src, src, 0, lvl);
	vis[src] = 1;
	for (int i = head[src]; i; i = edges[i].nxt){
		int v = edges[i].v;
		if (vis[v]) continue;
		get_weight(v, src);
		int rt = get_cent(v, src, w[v]);
		pre[rt] = src, dep[rt] = lvl + 1;
		decomp(rt, lvl + 1);
	}
}
void Init(int N, int A[], int B[], int D[]){
	n = N;
	for (int i = 0; i < N - 1; i++){
		A[i]++, B[i]++;
		add_edge(A[i], B[i], D[i]), add_edge(B[i], A[i], D[i]);
	}	
	get_weight(1, 1);
	decomp(get_cent(1, 1, N), 0);
	ms(ans, INF);
}
long long Query(int S, int X[], int T, int Y[]){
	for (int i = 0; i < S; i++)
		for (int src = X[i] + 1, l = dep[src], tmp = src; l >= 0; l--, tmp = pre[tmp]){
			if (ans[tmp] == LLINF) clr.push_back(tmp);
			ans[tmp] = min(ans[tmp], dist[l][src]);
		}
	ll ret = LLINF;
	for (int i = 0; i < T; i++)
		for (int src = Y[i] + 1, l = dep[src], tmp = src; l >= 0; l--, tmp = pre[tmp])
			ret = min(ret, dist[l][src] + ans[tmp]);
	for (int p : clr) ans[p] = LLINF;
	clr.clear();
	return ret;
}
