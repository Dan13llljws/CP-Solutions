#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4 + 5;
int n, k, a[MM], dp[MM];
int main(){
	freopen("teamwork.in", "r", stdin); freopen("teamwork.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++){
		scanf("%d", a + i); int mx = 0;
		for (int j = i - 1; j >= max(0, i - k); j--)
			mx = max(mx, a[j + 1]), dp[i] = max(dp[i], dp[j] + mx * (i - j));
	}
	printf("%d\n", dp[n]);
}	
