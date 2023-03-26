#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e5 + 5;
struct edge{int v, nxt, id;}edges[2*MM];
int n, m, q, t, tot, head[MM], in[MM], low[MM], psa[MM]; char ans[MM]; bool vis[MM];
void dfs(int src, int par){
	low[src] = in[src] = ++t;
	for (int i = head[src]; i != -1; i = edges[i].nxt){
		if (i == (par ^ 1)) continue;
		int v = edges[i].v;
		if (!in[v]) dfs(v, i), low[src] = min(low[src], low[v]);
		else low[src] = min(low[src], in[v]);
	}
}
void dfs1(int src){
	vis[src] = 1;
	for (int i = head[src]; i != -1; i = edges[i].nxt){
		int v = edges[i].v;
		if (vis[v]) continue;
		dfs1(v), psa[src] += psa[v];
		if (low[v] > in[src]){
			if (psa[v] > 0) ans[edges[i].id] = i & 1 ? 'R' : 'L';
			else if (psa[v] < 0) ans[edges[i].id] = i & 1 ? 'L' : 'R';
		} 
	}
}
int main(){
	n = re, m = re; memset(head, -1, sizeof head);
	for (int i = 0; i < m; i++){
		int a = re, b = re; ans[i] = 'B';
		edges[tot] = {b, head[a], i}, head[a] = tot++;
		edges[tot] = {a, head[b], i}, head[b] = tot++;
	}
	for (int i = 1; i <= n; i++) if (!in[i]) dfs(i, -1);
	q = re;
	while(q--) psa[re]++, psa[re]--;
	for (int i = 1; i <= n; i++) if (!vis[i]) dfs1(i);
	puts(ans);
}

