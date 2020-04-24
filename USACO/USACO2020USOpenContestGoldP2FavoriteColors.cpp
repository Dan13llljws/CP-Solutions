#include <bits/stdc++.h>
using namespace std;
const char sp=' ',nl='\n';
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define re read()
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define pb push_back
const int mod = 1e9 + 7, base = 131, MM = 2e5 + 5;
int n, m, dsu[MM], ans[MM]; bool vis[MM];
vector<int> adj[MM]; queue<int> q;
int Find(int x){
	return dsu[x] == x ? x : dsu[x] = Find(dsu[x]);
}
void unite(int a, int b){ // merge a into b
	a = Find(a), b = Find(b);
	if (a == b) return;
	dsu[a] = b;
	for (int x : adj[a]) adj[b].pb(Find(x));
	adj[a].clear();
}
int main(){
	n = re, m = re;
	for (int i = 0; i < m; i++){
		int a = re, b = re;
		adj[a].pb(b);
	}
	for (int i = 1; i <= n; i++){
		dsu[i] = i; 
		if (sz(adj[i]) > 1) q.push(i);
	}
	while(!q.empty()){
		int p = Find(q.front()); q.pop();
		if (sz(adj[p]) < 2) continue;
		int x = Find(adj[p].back());
		adj[p].pop_back();
		for (int v : adj[p])
			if (Find(v) != p) unite(v, x);
		for (int v : adj[x]) v = Find(v);
		sort(af(adj[x]));
		adj[x].resize(unique(af(adj[x])) - adj[x].begin());
		adj[p].clear(); adj[p].pb(x);
		q.push(x);
	}
	int co = 0;
	for (int i = 1; i <= n; i++){
		int t = Find(i);
		if (!ans[t]) ans[t] = ++co;
		pr(ans[t], nl);
	}
	return 0;
}
