#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define pb push_back
#define f first
#define s second
const int mod = 1e9 + 7, base = 131, MM = 1e6 + 5;
int n, ans = INF, best, sec, c[MM], d1[MM], d2[MM], nd1[MM], ndd[MM]; pii dd[MM];
vector<int> adj[MM];
void dfs(int src, int par){ // totally didnct copy the intended sol
	for (int v : adj[src]){
		if (v == par) continue;
		dfs(v, src);
		if (d1[v] > d1[src]) d2[src] = d1[src], d1[src] = d1[v], nd1[src] = v;
		else if (d1[v] > d2[src]) d2[src] = d1[v];
		if (dd[v] > dd[src]) dd[src] = dd[v], ndd[src] = v;
	}
	if (c[src] > 2){d1[src] = d2[src] = 0; dd[src] = {0, 0}; return;}
	if (c[src] == 2){sec = max(sec, min(d1[src], d2[src])), dd[src] = {d1[src], 0}, d1[src] = d2[src] = 0; return;}
	d1[src]++, dd[src].s++;
	best = max(best, d1[src] + d2[src]);
	if (nd1[src] == ndd[src]) sec = max(sec, min(dd[src].f, dd[src].s + d2[src]));
	else sec = max(sec, min(dd[src].f, dd[src].s + d1[src]));
}
int main(){
	n = re;
	for (int i = 1; i < n; i++){
		int a = re, b = re;
		adj[a].pb(b), adj[b].pb(a);
	}
	for (int i = 1; i <= n; i++) ans = min(ans, c[i] = re);
	if (ans > 2) return 0 * printf("%d/1\n", ans);
	dfs(1, 0);
	if (best > sec) printf("1/%d\n", best);
	else printf("2/%d\n", 2 * sec + 1);
}

