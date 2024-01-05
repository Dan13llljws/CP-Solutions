#include <bits/stdc++.h>
#ifdef DAN13
#include "../lib/debug.h"
#else
#define dbg(...)
#endif
using namespace std;
const int MM = 3005;
int n, a[MM], dp[MM][MM], psa[MM][MM];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		psa[a[i]][i]++;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) psa[i][j] += psa[i][j - 1];
	}
	for (int len = 1; len <= n; len++) {
		for (int l = 1, r = len; r <= n; l++, r++) {
			if (len == 1) { dp[l][r] = psa[a[l]][n] == 1; continue; }
			int wl = psa[a[l]][r] - psa[a[l]][l - 1] == psa[a[l]][n];
			int wr = psa[a[r]][r] - psa[a[r]][l - 1] == psa[a[r]][n];
			dp[l][r] = max(wl - dp[l + 1][r], wr - dp[l][r - 1]);
		}
	}
	int t = 0;
	for (int i = 1; i <= n; i++) t += psa[i][n] > 0;
	int x = (t + dp[1][n]) / 2, y = t - x;
	printf("%d:%d\n", x, y);
}
