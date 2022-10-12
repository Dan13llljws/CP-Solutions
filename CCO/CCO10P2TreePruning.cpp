#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 605;
int n, d, w[MM], tmp[MM], dp[MM][MM]; vector<int> adj[MM];
void dfs(int src){
	dp[src][300] = 0;
	for (int v : adj[src]){
		dfs(v), w[src] += w[v];
		for (int i = -n; i <= n; i++) tmp[i+300] = dp[src][i+300];
		for (int i = -n; i <= n; i++)
			for (int j = -n; j + i <= n; j++)
				tmp[i+300] = min(tmp[i+300], dp[src][i - j + 300] + dp[v][j + 300]);
		for (int i = -n; i <= n; i++) dp[src][i+300] = tmp[i+300];
	}
	dp[src][w[src] + 300] = 1;
}
int main(){
	n = re, d = re; memset(dp, 0x3f, sizeof dp);
	for (int i = 0; i < n; i++){
		int id = re; w[id] = 2 * re - 1; int c = re;
		while(c--) adj[id].push_back(re);
	}
	dfs(0); printf("%d\n", dp[0][w[0] - d + 300] > n ? -1 : dp[0][w[0] - d + 300]);
}

