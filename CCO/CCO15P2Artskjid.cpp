#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define ms(x, y) memset(x, y, sizeof x)
#define pb push_back
#define f first
#define s second
int n, m, ans, dp[1<<18][18];
vector<pii> adj[18];
int dfs(int mask, int src){
	if (src == n - 1) return 0;
	if (dp[mask][src] != -1) return dp[mask][src];
	dp[mask][src] = -1e9;
	for (pii v : adj[src]){
		if (mask >> v.f & 1) continue;
		dp[mask][src] = max(dp[mask][src], dfs(mask | (1 << v.f), v.f) + v.s);
	}
	return dp[mask][src];
}
int main(){
	n = re, m = re; ms(dp, -1);
	for (int i = 0; i < m; i++){
		int a = re, b = re, w = re;
		adj[a].pb({b, w});
	}
	printf("%d", dfs(1, 0));
}
