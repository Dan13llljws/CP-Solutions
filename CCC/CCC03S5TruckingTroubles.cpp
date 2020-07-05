#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define f first
#define s second
const int mod = 1e9 + 7, MM = 1e4 + 5;
struct edge{int a, b, w;};
int n, m, q, ans = INF, dsu[MM], dist[MM];
vector<pii> adj[MM]; vector<edge> edges;
bool cmp(edge a, edge b){return a.w > b.w;}
int Find(int x){return dsu[x] == x ? x : dsu[x] = Find(dsu[x]);}
void unite(int x, int y){dsu[Find(x)] = Find(y);}
void dfs(int src, int par){
	for (pii v : adj[src]){
		if (v.s == par) continue;
		dist[v.s] = min(dist[src], v.f);
		dfs(v.s, src);
	}
}
int main(){
	n = re, m = re, q = re, dist[1] = INF;
	for (int i = 0; i < m; i++) edges.push_back({re, re, re});
	sort(edges.begin(), edges.end(), cmp);
	for (int i = 1; i <= n; i++) dsu[i] = i;
	for (edge v : edges)
		if (Find(v.a) != Find(v.b)){
			unite(v.a, v.b);
			adj[v.a].push_back({v.w, v.b}), adj[v.b].push_back({v.w, v.a});
		}
	dfs(1, 1);
	for (int i = 0; i < q; i++) ans = min(ans, dist[re]);
	printf("%d", ans);
}
