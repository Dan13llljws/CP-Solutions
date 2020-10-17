#include <bits/stdc++.h>
using namespace std;
int n, g[16][16]; long long dp[1<<16], sum[1<<16];
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			scanf("%d", &g[i][j]);
	for (int mask = 0; mask < 1 << n; mask++)
		for (int i = 0; i < n; i++)
			if (mask >> i & 1)
				for (int j = i + 1; j < n; j++)
					if (mask >> j & 1)
						sum[mask] += g[i][j];
	for (int mask = 1; mask < 1 << n; mask++)
		for (int sub = mask; sub; sub = (sub - 1) & mask)
			dp[mask] = max(dp[mask], dp[mask ^ sub] + sum[sub]);
	printf("%lld", dp[(1<<n)-1]);
}
	
