#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f; const char sp=' ',nl='\n';
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define ms(x, y) memset(x, y, sizeof(x))
#define pb push_back
#define f first
#define s second
const int mod = 1e9 + 7, base = 131, MM = 1505, MN = 5e3 + 5;
struct edge{int b, w, id;};
int n, m, tot, dist[MM], vis[MM], to[MM], from[MM], ans[MN];
vector<edge> adj[MM];
void dijkstra(int src){
	ms(dist, inf); ms(to, 0); ms(from, 0); ms(vis, 0); 
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0, src}); dist[src] = 0, tot = 0, to[src] = 1;
	while(!q.empty()){
		int p = q.top().s, d = q.top().f; q.pop();
		if (d > dist[p]) continue;
		vis[tot++] = p;
		for (auto v : adj[p]){
			if (dist[v.b] > d + v.w){
				to[v.b] = to[p];
				dist[v.b] = d + v.w;
				q.push({dist[v.b], v.b});
			} else if (dist[v.b] == d + v.w) to[v.b] = (to[v.b] + to[p]) % mod;
		}
	}
	for (int i = tot - 1; i >= 0; i--){
		int t = vis[i]; from[t] = 1;
		for (auto v : adj[t]){
			if (dist[t] + v.w == dist[v.b]){
				ans[v.id] = (ans[v.id] + 1LL * to[t] * from[v.b]) % mod;
				from[t] = (from[t] + from[v.b]) % mod;
			}
		}
	}
}
int main(){
	n = re, m = re;
	for (int i = 0, a; i < m; i++) a = re, adj[a].pb({re, re, i});
	for (int i = 1; i <= n; i++) dijkstra(i);
	for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
	return 0;
}
