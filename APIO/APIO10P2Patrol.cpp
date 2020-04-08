#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)(x.size())
#define mp make_pair
#define pb push_back
#define f first
#define s second
const int mod = 1e9 + 7, base = 131;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MM = 1e5 + 5;
int N, K, d1, d2, far, cur, best[MM], sec[MM]; 
pii pre[MM];
vector<pii> adj[MM];
void dfs(int src, int par, int d){ // diameter
	if (d > d1) {d1 = d; far = src;}
	for (int i = 0; i < sz(adj[src]); i++){
		pii v = adj[src][i];
		if (v.s == par) continue;
		pre[v.s] = {src, i};
		dfs(v.s, src, d + v.f);
	}
}
void change(){ // flip the edges
	for (int x = far; x != cur; x = pre[x].f){
		int a = pre[x].f, b = x;
		adj[a][pre[x].s].f = -1;
		for (int i = 0; i < sz(adj[b]); i++){
			if (adj[b][i].s == a){
				adj[b][i].f = -1; break;
			}
		}
	}
}
void dp(int src, int par){ // finding diameter with negative edge
	best[src] = sec[src] = 0;
	int c1 = 0;
	for (auto v : adj[src]){
		if (v.s == par) continue;
		c1++;
		dp(v.s, src);
		int d = best[v.s] + v.f;
		if (d >= best[src]){
			sec[src] = best[src];
			best[src] = d;
		}
		else if (d > sec[src]) sec[src] = d;
	}
	if (!c1) return;
	if (c1 == 1) d2 = max(d2, best[src]);
	else if (c1 > 1) d2 = max(d2, best[src] + sec[src]);
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(N, K);
	for (int i = 1, a, b; i < N; i++){
		sc(a, b);
		adj[a].pb(mp(1, b)); adj[b].pb(mp(1, a));
	}
	dfs(1, 1, 0); d1 = 0; cur = far;
	dfs(far, far, 0);
	if (K == 1) {pr(2 * (N - 1) - d1 + 1); return 0;}
	change();
	dp(1, 1);
	pr(2 * N - d1 - d2);
	return 0;
}

