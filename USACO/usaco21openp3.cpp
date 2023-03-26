#include <bits/stdc++.h>
using namespace std;
const int MM = 155, mod = 1e9 + 7;
int n, cur, ans, psa[MM][MM], dp[2][MM][MM][2][2]; 
int get(int a, int b, int c, int d){
	return (c - a + 1) * (d - b + 1) == (psa[c][d] - psa[a - 1][d] - psa[c][b - 1] + psa[a - 1][b - 1]);
}
void add(int &a, int b){
	a += b;
	if (a >= mod) a -= mod;
	if (a < 0) a += mod;
}
void upd(int i, int a, int b, int c, int d, int i1, int j1, int v){
	add(dp[i][a][b][i1][j1], v), add(dp[i][a][d + 1][i1][j1], -v), add(dp[i][c + 1][b][i1][j1], -v), add(dp[i][c + 1][d + 1][i1][j1], v);
}
int main(){
	scanf("%d", &n); getchar();
	for (int i = 1; i <= n; i++, getchar())
		for (int j = 1; j <= n; j++)
			psa[i][j] = psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1] + (getchar() == 'G');
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			if (get(1, i, 1, j)) dp[0][i][j][0][0] = 1, ans++;
	for (int i = 1; i < n; i++, cur ^= 1){
		memset(dp[cur ^ 1], 0, sizeof dp[cur ^ 1]);
		for (int j = 1; j <= n; j++)
			for (int k = j; k <= n; k++){
				if (!get(i, j, i, k)) continue;
				upd(cur ^ 1, 1, k, j, n, 0, 0, dp[cur][j][k][0][0]);
				if (j < n && j < k) upd(cur ^ 1, j + 1, k, k, n, 1, 0, dp[cur][j][k][0][0]);
				if (k > 1 && j < k) upd(cur ^ 1, 1, j, j, k - 1, 0, 1, dp[cur][j][k][0][0]);
				if (j < k - 1) upd(cur ^ 1, j + 1, j, k, k - 1, 1, 1, dp[cur][j][k][0][0]);
				upd(cur ^ 1, 1, j, j, k, 0, 1, dp[cur][j][k][0][1]);
				if (j < k) upd(cur ^ 1, j + 1, j + 1, k, k, 1, 1, dp[cur][j][k][0][1]);
				upd(cur ^ 1, j, k, k, n, 1, 0, dp[cur][j][k][1][0]);
				if (j < k) upd(cur ^ 1, j, j, k - 1, k - 1, 1, 1, dp[cur][j][k][1][0]);
				upd(cur ^ 1, j, j, k, k, 1, 1, dp[cur][j][k][1][1]);
			}
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				for (int i1 : {0, 1}) for (int j1 : {0, 1}){
					add(dp[cur ^ 1][j][k][i1][j1], dp[cur ^ 1][j - 1][k][i1][j1]);
					add(dp[cur ^ 1][j][k][i1][j1], dp[cur ^ 1][j][k - 1][i1][j1]);
					add(dp[cur ^ 1][j][k][i1][j1], -dp[cur ^ 1][j - 1][k - 1][i1][j1]);
				}
		for (int j = 1; j <= n; j++)
			for (int k = j; k <= n; k++)
				 if (get(i + 1, j, i + 1, k)){
					add(dp[cur ^ 1][j][k][0][0], 1);
					for (int i1 : {0, 1}) for (int j1 : {0, 1})
						add(ans, dp[cur ^ 1][j][k][i1][j1]);
				}
	} printf("%d\n", ans);
}
				
	
