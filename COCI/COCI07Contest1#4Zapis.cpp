#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e5, base = 131;
int n, a[205]; ll dp[205][205]; bool lead;
ll fun(int l, int r){
	if (a[l] < 0 || a[r] > 0) return 0;
	if (!a[l] && !a[r]) return 3;
	return a[l] + a[r] == 0 || a[l] * a[r] == 0;
}
int main(){
	scanf("%d", &n); getchar();
	for (int i = 1; i <= n; i++){
		char c = getchar();
		if (c == '(') a[i] = 1;
		else if (c == ')') a[i] = -1;
		else if (c == '[') a[i] = 2;
		else if (c == ']') a[i] = -2;
		else if (c == '{') a[i] = 3;
		else if (c == '}') a[i] = -3;
	}
	if (n % 2) return 0 * printf("0\n");
	for (int i = 1; i <= n + 2; i++) dp[i][i - 1] = 1;
	for (int len = 2; len <= n; len += 2)
		for (int l = 1, r = l + len - 1; r <= n; l++, r++)	
			for (int i = l + 1; i <= r; i += 2){
				dp[l][r] += fun(l, i) * dp[l + 1][i - 1] * dp[i + 1][r];
				if (dp[l][r] >= mod && l == 1 && r == n) lead = 1;
				dp[l][r] %= mod;
			}
	if (lead) printf("%05lld\n", dp[1][n]);
	else printf("%lld\n", dp[1][n]);
	return 0;
}
