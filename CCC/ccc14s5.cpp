#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define sqr(x) ((x)*(x))
const int mod = 1e9 + 7, base = 131, MM = 2005;
struct edge{int u, v, w;}edges[MM*MM];
int n, tot, ans, x[MM], y[MM], dp[MM], pd[MM], dist[MM];
bool cmp(edge a, edge b){return a.w < b.w;}
int main(){
	n = re; 
	for (int i = 1; i <= n; i++) x[i] = re, y[i] = re;
	for (int i = 0; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			edges[tot++] = {i, j, sqr(x[i] - x[j]) + sqr(y[i] - y[j])};
	sort(edges, edges + tot, cmp);
	for (int i = 0; i < tot; i++){
		int u = edges[i].u, v = edges[i].v, w = edges[i].w;
		if (w != dist[u]) dist[u] = w, pd[u] = dp[u];
		if (w != dist[v]) dist[v] = w, pd[v] = dp[v];
		dp[u] = max(dp[u], pd[v] + 1);
		if (u) dp[v] = max(dp[v], pd[u] + 1);
	}
	printf("%d", dp[0]);
}

 
 
