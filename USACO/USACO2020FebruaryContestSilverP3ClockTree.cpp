#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define pb push_back
const int MM = 2505;
int N, c[MM], dist[MM], ans;
vector<int> adj[MM];
void dfs(int src, int par, int d){
	dist[src] = d;
	for (int v : adj[src]){
		if (v == par) continue;
		dfs(v, src, d + 1);
	}
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(N);
	for (int i = 1; i <= N; i++) sc(c[i]);
	for (int i = 1, a, b; i < N; i++){
		sc(a, b);
		adj[a].pb(b); adj[b].pb(a);
	}
	for (int i = 1; i <= N; i++){
		dfs(i, 0, 0);
		int odd = 0, even = 0;
		for (int j = 1; j <= N; j++){
			if (dist[j] % 2) odd += c[j];
			else even += c[j];
		}
		if (odd % 12 == even % 12 || (odd + 1) % 12 == even % 12) ans++;
	}
	pr(ans);
	return 0;
}

