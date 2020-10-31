#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, MM = 1e3 + 5;
int n, m, tot, ans = 1, dsu[MM*MM], id[MM][MM], dp[MM*MM]; char g[MM][MM]; 
int Find(int x){return dsu[x] == x ? x : dsu[x] = Find(dsu[x]);}
void unite(int x, int y){dsu[Find(x)] = Find(y);}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%s", g[i] + 1);
	for (int i = n - 1; i > 1; i--){
		for (int j = 2; j < m; j++){
			if (g[i][j] == '#') continue;
			if (g[i][j - 1] == '#') id[i][j] = ++tot, dsu[tot] = tot, dp[tot] = 1;
			else id[i][j] = tot;
			if (g[i + 1][j] == '.'){
				int tmp = Find(id[i + 1][j]);
				if (tmp != tot) dsu[tmp] = tot, dp[tot] = 1LL * dp[tot] * dp[tmp] % mod;
			}
		}
		for (int j = 2; j < m; j++)
			if (g[i][j - 1] == '#' && Find(id[i][j]) == id[i][j]) dp[id[i][j]]++;
	}
	for (int i = 1; i <= tot; i++)
		if (i == Find(i)) ans = 1LL * ans * dp[i] % mod;
	printf("%d\n", ans);
}
