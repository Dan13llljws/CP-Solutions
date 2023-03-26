#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e5 + 5;
int n, m, t, cnt, top, st[MM], in[MM], low[MM], s[MM*2], w[MM*2]; ll ans; vector<int> adj[MM], adj2[MM*2]; 
void tarjan(int src, int par){
	in[src] = low[src] = ++t, st[++top] = src, w[src] = -1;
	for (int v : adj[src]){
		if (!in[v]){
			tarjan(v, src), low[src] = min(low[src], low[v]);
			if (low[v] == in[src]){
				cnt++, w[cnt] = 1;
				for (int x = 0; x != v;){
					x = st[top--], w[cnt]++;
					adj2[x].push_back(cnt), adj2[cnt].push_back(x);
				} adj2[cnt].push_back(src), adj2[src].push_back(cnt);
			}
		} else low[src] = min(low[src], in[v]);	
	}
}
void dfs(int src, int par){
	s[src] = (src <= n);
	for (int v : adj2[src]){
		if (v == par) continue;
		dfs(v, src);
		ans += 1LL * w[src] * s[src] * s[v];
		s[src] += s[v];
	} ans += 1LL * w[src] * s[src] * (t - s[src]);
}
int main(){
	cnt = n = re, m = re;
	for (int i = 0; i < m; i++){
		int a = re, b = re;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		if (!in[i]) t = 0, tarjan(i, 0), dfs(i, 0);
	printf("%lld\n", ans * 2);
}

