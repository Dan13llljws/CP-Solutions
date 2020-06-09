#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define pb push_back
#define f first
#define s second
const int mod = 1e9 + 7, MM = 1e3 + 5;
int n, m, cnt, mn, color[MM], s[MM][2]; bool vis[MM], dp[MM][MM]; char ans[MM]; 
vector<int> adj[MM];
void dfs(int src, int t, int g){
	s[g][t]++, color[src] = t, vis[src] = 1;
	for (int v : adj[src]){
		if (vis[v] && color[v] == color[src]){puts("-1"); exit(0);}
		if (vis[v]) continue;
		dfs(v, t ^ 1, g);
	}
}
void paint(int src, int col){
	ans[src] = col + '1';
	for (int v : adj[src])
		if (!ans[v]) paint(v, col ^ 1);
}
int main(){
	n = re, m = re;
	for (int i = 0; i < m; i++){
		int a = re, b = re;
		adj[a].pb(b), adj[b].pb(a);
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i]) dfs(i, 0, ++cnt);
	dp[cnt + 1][0] = 1;
	for (int i = cnt; i; i--)
		for (int j = n; j >= 0; j--){
			if (j >= s[i][0] && dp[i + 1][j - s[i][0]]) dp[i][j] = 1;
			if (j >= s[i][1] && dp[i + 1][j - s[i][1]]) dp[i][j] = 1;
		}
	for (int i = n / 2; i >= 0; i++) if (dp[1][i]){mn = i; break;}
	cnt = 0; int curs = 0;
	for (int i = 1; i <= n; i++)
		if (!ans[i]){
			cnt++;
			if (dp[cnt + 1][mn - s[cnt][0] - curs]) paint(i, 0), curs += s[cnt][0];
			else paint(i, 1), curs += s[cnt][1];
		}
	puts(ans + 1);
}
