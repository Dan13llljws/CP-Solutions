#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
struct edge{int v, nxt;}edges[100005];
int n, m, tot, ans, head[100005], dp[100005];
int dfs(int src){
	if (dp[src]) return dp[src];
	for (int i = head[src]; i; i = edges[i].nxt)
		dp[src] = max(dp[src], dfs(edges[i].v) + 1);
	return dp[src];
}
int main(){
	n = read(), m = read();
	for (int i = 0; i < m; i++){
		int a = read(), b = read();
		edges[++tot].v = b, edges[tot].nxt = head[a], head[a] = tot;
	}
	for (int i = 1; i <= n; i++) ans = max(ans, dfs(i));
	printf("%d", ans);
}
