#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 4e5 + 5;
int n, dia, best[MM], cnt[MM]; ll ans; vector<int> adj[MM];
void dfs(int src, int par){
	cnt[src] = 1;
	for (int v : adj[src]){
		if (v == par) continue;
		dfs(v, src);
		if (best[src] + best[v] + 1 > dia){
			dia = best[src] + best[v] + 1;
			ans = 1LL * cnt[src] * cnt[v];
		} else if (best[src] + best[v] + 1 == dia)
			ans += 1LL * cnt[src] * cnt[v];
		if (best[v] + 1 > best[src]){
			best[src] = best[v] + 1;
			cnt[src] = cnt[v];
		} else if (best[v] + 1 == best[src])
			cnt[src] += cnt[v];
	}
}
int main(){
	n = re;
	for (int i = 1; i < n; i++){
		int a = re, b = re;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	dfs(1, 0); printf("%d %lld\n", dia + 1, ans);
}
