#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5, mod = 1e9 + 7;
int n, ans, dp[MM][4][4][4], mp[256]; char s[MM];
int main(){
	scanf("%s", s); n = strlen(s); mp['A'] = 0, mp['C'] = 1, mp['G'] = 2, mp['T'] = 3;
	for (int i = 0; i < 4; i++)
		if (s[0] == '?' || mp[s[0]] == i)
			for (int j = 0; j < 4; j++)
				dp[0][j][i][i] = 1;
	for (int i = 0; i < n - 1; i++)
		for (int a = 0; a < 4; a++)
			for (int b = 0; b < 4; b++)
				for (int c = 0; c < 4; c++)
					for (int d = 0; d < 4; d++)
						if (s[i + 1] == '?' || mp[s[i + 1]] == d){
							if (a == c) dp[i + 1][b][d][d] = (dp[i + 1][b][d][d] + dp[i][a][b][c]) % mod;
							if (d != c) dp[i + 1][a][b][d] = (dp[i + 1][a][b][d] + dp[i][a][b][c]) % mod;
						}
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) 
			ans = (ans + dp[n - 1][i][j][i]) % mod;
	printf("%d\n", ans);
}
