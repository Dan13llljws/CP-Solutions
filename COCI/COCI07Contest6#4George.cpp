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
const int MM = 1e3 + 5;
int N, M, A, B, K, G, a, b, cur, st[MM][MM], ed[MM][MM], adj[MM][MM], seq[MM], dist[MM];
priority_queue<pii, vector<pii>, greater<pii>> q;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(N, M, A, B, K, G); ms(st, -1); ms(ed, -1);
	for (int i = 0; i < G; i++) sc(seq[i]);
	for (int i = 0, w; i < M; i++){
		sc(a, b, w);
		adj[a][b] = w; adj[b][a] = w;
	}
	for (int i = 1; i < G; i++){
		int s = seq[i - 1], t = seq[i];
		st[s][t] = cur; st[t][s] = cur;
		cur += adj[s][t];
		ed[s][t] = cur - 1; ed[t][s] = cur - 1;
	}
	ms(dist, INF); dist[A] = K; q.push({K, A});
	while(!q.empty()){
		int p = q.top().s, d = q.top().f; q.pop();
		if (d > dist[p]) continue;
		for (int i = 1; i <= N; i++){
			if (!adj[p][i]) continue;
			if (d >= st[p][i] && d <= ed[p][i] && dist[i] > ed[p][i] + adj[p][i]){
				dist[i] = ed[p][i] + adj[p][i];
				q.push({dist[i], i});
			}
			else if (dist[i] > dist[p] + adj[p][i]){
				dist[i] = dist[p] + adj[p][i];
				q.push({dist[i], i});
			}
		}
	}
	pr(dist[B] - K + 1);
	return 0;
}

