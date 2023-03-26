#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1005;
int n, m, ans, t, top, tot, st[MM], p[MM], tin[MM], in[MM], low[MM]; vector<int> adj[MM]; 
void dfs(int src, int par){
	tin[src] = low[src] = ++t, st[++top] = src;
	for (int v : adj[src]){
		if (v == par) continue;
		if (tin[v]) low[src] = min(low[src], tin[v]);
		else dfs(v, src), low[src] = min(low[src], low[v]); 
	}
	if (low[src] == tin[src]){
		tot++;
		while(1){
			int v = st[top--]; 	
			p[v] = tot;
			if (v == src) break;
		}
	}
}
int main(){
	n = re, m = re;
	for (int i = 0; i < m; i++){
		int a = re, b = re;
		adj[a].push_back(b), adj[b].push_back(a);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
		for (int v : adj[i]) 
			if (low[v] > tin[i]) 
				in[p[v]]++, in[p[i]]++;
	for (int i = 1; i <= tot; i++) ans += in[i] == 1;
	printf("%d", (ans + 1) / 2);
}

