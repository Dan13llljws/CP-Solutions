#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e5 + 5;
int n, m, s, t, x, y; ll ans, d[4][MM], dp[2][MM]; vector<pii> adj[MM]; vector<int> ord; priority_queue<array<ll,2>> q;
void dijkstra(int src, ll dist[]){
	dist[src] = 0, q.push({0, src}); ord.clear();
	while(q.size()){
		int u = q.top()[1]; ll dis = -q.top()[0]; q.pop();
		if (dis > dist[u]) continue;
		ord.push_back(u);
		for (pii v : adj[u])
			if (dist[v.second] > dist[u] + v.first)
				dist[v.second] = dist[u] + v.first, q.push({-dist[v.second], v.second});
	}
}
int main(){
	n = re, m = re, s = re, t = re, x = re, y = re;
	for (int i = 0; i < m; i++){
		int a = re, b = re, c = re;
		adj[a].push_back({c, b}), adj[b].push_back({c, a});
	}
	memset(d, inf, sizeof d); memset(dp, inf, sizeof dp);
	dijkstra(t, d[1]), dijkstra(x, d[2]), dijkstra(y, d[3]); dijkstra(s, d[0]);
	dp[0][s] = d[2][s], dp[1][s] = d[3][s], dp[0][x] = 0, dp[1][y] = 0, ans = d[2][y];
	for (int u : ord){
		ans = min({ans, dp[0][u] + d[3][u], dp[1][u] + d[2][u]});
		for (pii v : adj[u]) 
			if (d[0][u] + v.first + d[1][v.second] == d[0][t])
				dp[0][v.second] = min({dp[0][v.second], dp[0][u], d[2][v.second]}), dp[1][v.second] = min({dp[1][v.second], dp[1][u], d[3][v.second]});
	}
	printf("%lld\n", ans);
}
