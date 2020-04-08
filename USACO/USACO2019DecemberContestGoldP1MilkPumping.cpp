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
typedef pair<int, pii> pip;
const int MM = 1e3 + 5;
int N, M, dist[MM][MM], ans, maxf;
vector<pip> adj[MM];
priority_queue<pip, vector<pip>, greater<pip>> q;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(N, M); 
	for (int i = 0, a, b, f, c; i < M; i++){
		sc(a, b, c, f); maxf = max(maxf, f);
		adj[a].pb({b, {f, c}}); adj[b].pb({a, {f, c}});
	}
	ms(dist, INF); dist[1][maxf] = 0;
	q.push({0, {1, maxf}});
	while(!q.empty()){
		int p = q.top().s.f, f = q.top().s.s, c = q.top().f; q.pop();
		if (c > dist[p][f]) continue;
		for (auto v : adj[p]){
			int t = min(v.s.f, f); 
			if (dist[v.f][t] > c + v.s.s){
				dist[v.f][t] = c + v.s.s;
				q.push({dist[v.f][t], {v.f, t}});
			}
		}
	}
	for (int i = 0; i <= maxf; i++) ans = max(ans, 1000000 * i / dist[N][i]);
	pr(ans);
	return 0;
}

