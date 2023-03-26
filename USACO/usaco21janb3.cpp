#include <bits/stdc++.h>
using namespace std;
int n, a[22], b[22]; long long ans = 1;
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	for (int i = 0; i < n; i++) scanf("%d", b + i);
	sort(a, a + n), sort(b, b + n);
	for (int i = n - 1; i >= 0; i--)
		ans *= -(lower_bound(b, b + n, a[i]) - b)  + i + 1;
	printf("%lld\n", ans);
}
