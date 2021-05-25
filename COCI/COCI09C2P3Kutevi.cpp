#include <stdio.h>
#include <cstring>
using namespace std;
int n, k, a[11], dp[361];
int dfs(int x){
	if (dp[x] != -1) return dp[x];
	if (!x) return 1;
	dp[x] = 0;
	for (int i = 0; i < n; i++) dp[x] |= dfs((x + a[i]) % 360) | dfs((x - a[i] + 360) % 360);
	return dp[x];
}
int main(){
	scanf("%d%d", &n, &k); memset(dp, -1, sizeof dp); 
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	for (int i = 0, x; i < k; i++) scanf("%d", &x), puts(dfs(x) | dfs(360 - x) ? "YES" : "NO");
}
