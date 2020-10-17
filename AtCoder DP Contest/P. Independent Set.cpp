#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
const int mod = 1e9 + 7, MM = 2e5 + 5;
struct edge{int v, nxt;}edges[MM];
int n, tot, head[MM], dp[MM][2];
void dfs(int src, int par){
	dp[src][1] = dp[src][0] = 1;
	for (int i = head[src]; i; i = edges[i].nxt){
		int v = edges[i].v;
		if (v == par) continue;
		dfs(v, src);
		dp[src][1] = 1LL * dp[src][1] * dp[v][0] % mod;
		dp[src][0] = 1LL * dp[src][0] * (dp[v][0] + dp[v][1]) % mod;
	}
}
int main(){
	n = read();
	for (int i = 1; i < n; i++){
		int a = read(), b = read();
		edges[++tot].v = b, edges[tot].nxt = head[a], head[a] = tot;
		edges[++tot].v = a, edges[tot].nxt = head[b], head[b] = tot;
	}
	dfs(1, 1);
	printf("%d", (dp[1][0] + dp[1][1]) % mod);
}
