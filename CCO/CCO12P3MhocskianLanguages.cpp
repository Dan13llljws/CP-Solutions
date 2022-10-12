#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, v, w, t, r1, r2; char up[26], low[26], r1a[30], r1b[30], r2a[30], r2b[30], r2c[30], s[31]; bool dp[31][31][26];
int main(){
	scanf("%d%d", &v, &t);
	for (int i = 0; i < v; i++) scanf(" %c ", up + i);
	for (int i = 0; i < t; i++) scanf(" %c ", low + i); 
	scanf("%d", &r1);
	for (int i = 0; i < r1; i++) scanf(" %c %c ", r1a + i, r1b + i);
	scanf("%d", &r2);
	for (int i = 0; i < r2; i++) scanf(" %c %c %c ", r2a + i, r2b + i, r2c + i);
	scanf("%d", &w);
	while(w--){
		scanf("%s", s + 1); n = strlen(s + 1); memset(dp, 0, sizeof dp);
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < r1; j++)
				if (r1b[j] == s[i]) dp[i][i][r1a[j] - 'A'] = 1;
		for (int len = 2; len <= n; len++)
			for (int l = 1, r = len; r <= n; l++, r++)
				for (int i = l; i < r; i++)
					for (int j = 0; j < r2; j++)
						dp[l][r][r2a[j] - 'A'] |= dp[l][i][r2b[j] - 'A'] & dp[i + 1][r][r2c[j] - 'A'];
		printf("%d\n", dp[1][n][up[0] - 'A']);
	}
}

