#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6 + 5;
int n, in[MM], ans[MM]; long long k;
int main(){
	scanf("%d%lld", &n, &k);
	for (int i = 1; i < n - 1; i++)
		if (__builtin_popcount(n - 1 - i) == 1) continue;
		else if (k >= n - 1 - i) k -= n - 1 - i, in[i] = 1;
	for (int i = 30; i >= 0; i--){
		if ((1 << i) > n - 2) continue;
		if (k >= (1 << i)) k -= 1 << i, in[n - 1 - (1 << i)] = 1;
	}
	if (k) return 0 * puts("-1");
	for (int i = 1; i < n - 1; i++)
		if (!in[i]) printf("%d ", i);
	printf("%d ", n - 1);
	for (int i = 1; i < n - 1; i++)
		if (in[i]) printf("%d ", i);
	printf("%d\n", n);
}
