#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5, mod = 1e9 + 7;
int n, ans, p[MM], x[MM], y[MM], psa[2*MM];
int main(){
	scanf("%d", &n); p[0] = 1;
	for (int i = 1; i <= n; i++) p[i] = p[i - 1] * 2 % mod;
	for (int i = 0; i < n; i++) scanf("%d%d", x + i, y + i), psa[x[i]]++, psa[y[i]]--;
	for (int i = 1; i <= 2 * n; i++) psa[i] += psa[i - 1];
	for (int i = 0; i < n; i++) ans = (ans + p[n - psa[x[i]]]) % mod;
	printf("%d\n", ans);
}
	
		
	
