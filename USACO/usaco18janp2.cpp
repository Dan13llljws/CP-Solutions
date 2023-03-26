#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 70005;
int n, dis[MM], w[MM], vis[MM], bit[2*MM], ans[MM]; vector<int> adj[MM], res; vector<pii> tmp; queue<int> q;
void upd(int x, int v){
	for (; x <= 2 * n; x += x & -x) bit[x] += v, res.push_back(x);
}
int get(int x){
	int ret = 0;
	for (; x; x -= x & -x) ret += bit[x];
	return ret;
}
int get_weight(int src, int par){
	w[src] = 1;
	for (int v : adj[src])
		if (v != par && !vis[v]) w[src] += get_weight(v, src);
	return w[src];
}
int get_cent(int src, int par, int wt){
	for (int v : adj[src])
		if (v != par && !vis[v] && w[v] * 2 > wt) return get_cent(v, src, wt);
	return src;
}
void dfs(int src, int par, int d){
	ans[src] += get(d + n);
	tmp.push_back({dis[src] - d, 2 - adj[src].size()});
	for (int v : adj[src])
		if (!vis[v] && v != par) dfs(v, src, d + 1);
}
void get_ans(int src){
	for (int v : adj[src]){
		if (vis[v]) continue;
		dfs(v, src, 1);
		for (pii x : tmp) upd(x.first + n, x.second);
		tmp.clear();
	}
	for (int x : res) bit[x] = 0;
	res.clear(), reverse(adj[src].begin(), adj[src].end());
	upd(dis[src] + n, 2 - adj[src].size());
	for (int v : adj[src]){
		if (vis[v]) continue;
		dfs(v, src, 1);
		for (pii x : tmp) upd(x.first + n, x.second);
		tmp.clear();
	}
	ans[src] += get(n);
	for (int x : res) bit[x] = 0;
	res.clear();
}
void divide(int src){
	get_ans(src); vis[src] = 1;
	for (int v : adj[src])
		if (!vis[v]) divide(get_cent(v, v, get_weight(v, v)));
}
int main(){	
	n = re; memset(dis, inf, sizeof dis);
	for (int i = 1; i < n; i++){
		int a = re, b = re;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) 
		if ((int)adj[i].size() == 1) q.push(i), dis[i] = 0, ans[i]--;
	while(q.size()){
		int src = q.front(); q.pop();
		for (int v : adj[src])
			if (dis[v] > dis[src] + 1)
				dis[v] = dis[src] + 1, q.push(v);
	}
	divide(get_cent(1, 1, get_weight(1, 1)));
	for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
}
