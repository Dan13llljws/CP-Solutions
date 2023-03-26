#include <bits/stdc++.h>
using namespace std;
int n, a[101], dp[101][101], c[101][101];
int main(){
	scanf("%d", &n); memset(dp, 0x3f, sizeof dp); dp[0][0] = 0;
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			c[i][j] = c[i][j - 1] + (a[j] != j - i);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			for (int k = 0; k < i; k++)
				dp[i][j] = min(dp[i][j], dp[k][j - 1] + c[k + 1][i]);
	for (int i = 1; i <= n; i++) printf("%d\n", dp[n][i]);
}

