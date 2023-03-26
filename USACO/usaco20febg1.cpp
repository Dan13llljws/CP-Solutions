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
int N, M, C, in[MM], dist[MM];
vector<pii> adj[MM];
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(N, M, C);
	for (int i = 1; i <= N; i++) sc(dist[i]);
	for (int i = 0, a, b, w; i < C; i++){
		sc(a, b, w); in[b]++;
		adj[a].pb(mp(w, b));
	}
	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (!in[i]) q.push(i);
	while(sz(q)){
		int p = q.front(); q.pop();
		for (auto v : adj[p]){
			dist[v.s] = max(dist[v.s], dist[p] + v.f);
			if (!--in[v.s]) q.push(v.s);
		}
	}
	for (int i = 1; i <= N; i++) pr(dist[i], nl);
	return 0;
}

