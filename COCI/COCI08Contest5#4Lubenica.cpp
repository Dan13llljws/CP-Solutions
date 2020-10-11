#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, h, cnt[21], m[21], g[21][21], ord[1<<20]; ll ans, tot[1<<20]; 
int main(){
	scanf("%d %d ", &n, &h);
	for (int i = 0; i < n; i++, getchar())
		for (int j = 0; j < n; j++)
			if (getchar() == '1') cnt[i]++, m[i] |= 1 << j;
	int mask = m[0]; ans = tot[mask] = cnt[0], ord[mask] = 1;
	for (int r = 2; r <= h; r++){
		int nxt = 0;
		for (int i = 0; i < n; i++){
			if (mask >> i & 1) nxt ^= m[i], ans += cnt[i];
			else ans += 2 * cnt[i];
		}
		mask = nxt;
		if (!ord[mask]) ord[mask] = r, tot[mask] = ans;
		else {
			int rep = (h - r) / (r - ord[mask]);
			r += rep * (r - ord[mask]), ans += rep * (ans - tot[mask]);
			memset(ord, 0, sizeof ord);
		}
	}
	printf("%lld\n", ans);
}

