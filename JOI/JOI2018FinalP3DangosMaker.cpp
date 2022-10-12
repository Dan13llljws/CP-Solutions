#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, MM = 3005;
int n, m, ans; char g[MM][MM];
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%s", g[i] + 1);
	for (int i = 2; i <= n + m; i++){
		int dp = 0, dp1 = 0, dp2 = 0;
		for (int x = min(i - 1, n), y = max(1, i - x); x >= 1 && y <= m; x--, y++){
			int tmp = dp;
			dp = max(dp1, dp2);
			if (g[x][y] != 'G') continue;
			if (g[x - 1][y] == 'R' && g[x + 1][y] == 'W') dp1 = max(tmp, dp1) + 1;
			if (g[x][y - 1] == 'R' && g[x][y + 1] == 'W') dp2 = max(tmp, dp2) + 1;
		}
		ans += max({dp, dp1, dp2});
	}
	printf("%d\n", ans);
}
