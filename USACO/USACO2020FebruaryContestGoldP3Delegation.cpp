#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
const int mod = 1e9 + 7, base = 131;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MM = 1e5 + 5;
int N, dist[MM], vis[MM];
vector<int> adj[MM];
bool dfs(int src, int par, int f){
	map<int, int> cnt; dist[src] = 0;
	for (int v : adj[src]){
		if (v == par) continue;
		if (!dfs(v, src, f)) return 0;
		int d = (dist[v] + 1) % f;
		if (d){
			if (cnt[f - d]) cnt[f - d]--;
			else cnt[d]++;
		}
	}
	int c1 = 0, val = 0;
	for (auto m : cnt)
		if (m.s) c1 += m.s, val = m.f;
	if (c1 == 0) return 1;
	if (c1 == 1){
		dist[src] = val;
		return 1;
	}
	if (c1 > 1) return 0;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(N);
	for (int i = 1, a, b; i < N; i++){
		sc(a, b);
		adj[a].pb(b); adj[b].pb(a);
	}
	for (int i = N - 1; i; i--){
		if (vis[i]) continue;
		if ((N - 1) % i) vis[i] = 1;
		else if (dfs(1, 1, i)){
			for (int j = i; j; j--)
				if (i % j == 0) vis[j] = 2;
		}
		else vis[i] = 1;	
	}
	for (int i = 1; i < N; i++) pr(vis[i] - 1);
	return 0;
}
