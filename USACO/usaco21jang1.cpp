#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
char s[MM]; int n, m, g[22][22], dp[1<<20], mp[256];
int main(){
	scanf("%s", s); n = strlen(s); memset(mp, -1, sizeof mp);
	for (int i = 0; i < n; i++){
		if (mp[s[i]] == -1) mp[s[i]] = m++;
		if (i) g[mp[s[i - 1]]][mp[s[i]]]++;
	}
	memset(dp, 0x3f, sizeof dp); dp[0] = n;
	for (int mask = 0; mask < (1 << m); mask++){
		for (int i = 0; i < m; i++){
			if (mask >> i & 1) continue;
			int cnt = 0;
			for (int j = 0; j < m; j++)
				if (mask >> j & 1) cnt += g[i][j];
			dp[mask|(1<<i)] = min(dp[mask|(1<<i)], dp[mask] - cnt);
		}
	}
	printf("%d\n", dp[(1<<m)-1]);
}

			
