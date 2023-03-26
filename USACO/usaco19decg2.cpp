#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
const char sp=' ',nl='\n';
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
template<typename T>void read(T &s){s=0;char ch=getchar();ll f=1;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')s=(s<<3)+(s<<1)+ch-48,ch=getchar();s*=f;}
template<typename T, typename...A>void read(T&f,A&...a){read(f);read(a...);}
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define re read()
#define sz(x) (int)(x.size())
#define pb push_back
const int mod = 1e9 + 7, base = 131, MM = 1e5 + 5;
struct query{int a, b, c; bool ans;}q[MM];
int n, m, t[MM], anc[MM][20], dep[MM];
vector<int> adj[MM], ed[MM], st[MM];
void dfs(int src, int par){
	dep[src] = dep[par] + 1;
	anc[src][0] = par;
	for (int i = 1; i <= ceil(log2(n)); i++) anc[src][i] = anc[anc[src][i - 1]][i - 1];
	for (int v : adj[src])
		if (v != par) dfs(v, src);
}	
int lca(int u, int v){
	int LG = ceil(log2(n));
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = LG; i >= 0; i--)
		if (dep[u] - (1 << i) >= dep[v]) u = anc[u][i];
	if (u == v) return u;
	for (int i = LG; i >= 0; i--)
		if (anc[u][i] != anc[v][i])
			u = anc[u][i], v = anc[v][i];
	return anc[u][0];
}
void dfs2(int src, int par){
	st[t[src]].pb(src);
	for (int i : ed[src]){
		if (!sz(st[q[i].c])) continue;
		int other = q[i].a + q[i].b - src, color = st[q[i].c].back();
		if (lca(src, other) == color) q[i].ans = 1;
		else if (!(lca(other, color) == color)) q[i].ans = 1;
	}
	for (int v : adj[src])
		if (v != par) dfs2(v, src);
	st[t[src]].pop_back();
}
int main(){
	n = re, m = re;
	for (int i = 1; i <= n; i++) t[i] = re;
	for (int i = 0, a, b; i < n - 1; i++){
		a = re, b = re;
		adj[a].pb(b); adj[b].pb(a);
	}
	dfs(1, 0);
	for (int i = 0; i < m; i++){
		read(q[i].a, q[i].b, q[i].c);
		ed[q[i].a].pb(i); ed[q[i].b].pb(i);
	}
	dfs2(1, 0);
	for (int i = 0; i < m; i++) pr(q[i].ans);
	return 0;
}
