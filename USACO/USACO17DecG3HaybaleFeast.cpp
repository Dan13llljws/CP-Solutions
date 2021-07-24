#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5 + 5;
int n, ql, qr, ans = 1e9, s[MM], q[MM]; ll m, psa[MM];
int main(){
	//freopen("hayfeast.in", "r", stdin); freopen("hayfeast.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int l = 0, r = 1; r <= n; r++){
		scanf("%d%d", psa + r, s + r); psa[r] += psa[r - 1];
		while(psa[r] - psa[l] >= m) l++;
		while(ql <= qr && q[ql] < l) ql++;
		while(ql <= qr && s[r] >= s[q[qr]]) qr--;
		q[++qr] = r;
		if (psa[r] - psa[l - 1] >= m) ans = min(ans, s[q[ql]]);
	}
	printf("%d\n", ans);
}
