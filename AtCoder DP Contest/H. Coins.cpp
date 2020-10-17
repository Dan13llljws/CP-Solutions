#include <bits/stdc++.h>
using namespace std;
int n; double dp[3000][3000], p, ans;
int main(){
	scanf("%d", &n); dp[0][0] = 1.0;
	for (int i = 1; i <= n; i++){
		scanf("%lf", &p); 
		for (int j = 0; j <= i; j++)
			dp[i][j] = dp[i - 1][j] * (1 - p) + dp[i - 1][j - 1] * p;
	}
	for (int i = n + 1 >> 1; i <= n; i++) ans += dp[n][i];
	printf("%.9f", ans);	
}
