#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, MM = 75;
int n, k, id[MM], val[MM], p[MM], w[MM], dp[MM][MM][MM]; vector<int> cmp;
int main(){
	scanf("%d%d", &n, &k); iota(id, id + n + 1, 0); memset(dp, 0x3f, sizeof dp);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++) dp[i + 1][i][j] = 0;
	for (int i = 1; i <= n; i++) scanf("%d", val + i);
	for (int i = 1; i <= n; i++) scanf("%d", p + i), cmp.push_back(p[i]);
	for (int i = 1; i <= n; i++) scanf("%d", w + i);
	sort(cmp.begin(), cmp.end());
	for (int i = 1; i <= n; i++) p[i] = lower_bound(cmp.begin(), cmp.end(), p[i]) - cmp.begin();
	sort(id + 1, id + 1 + n, [&](int a, int b){return val[a] < val[b];});
	for (int i = 1; i <= n; i++) w[id[i]] += w[id[i - 1]];
	for (int len = 1; len <= n; len++)	
		for (int l = 1, r = len; r <= n; l++, r++){
			for (int i = l; i <= r; i++){
				for (int j = 0; j < n; j++){
					dp[l][r][j] = min(dp[l][r][j], w[id[r]] - w[id[l - 1]] + dp[l][i - 1][j] + dp[i + 1][r][j] + k);
					if (j <= p[id[i]])
						dp[l][r][j] = min(dp[l][r][j], w[id[r]] - w[id[l - 1]] + dp[l][i - 1][p[id[i]]] + dp[i + 1][r][p[id[i]]]);
				}
			}
		}
	printf("%d\n", dp[1][n][0]);
}

