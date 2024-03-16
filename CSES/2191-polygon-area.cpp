#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);
	x.push_back(x[0]), y.push_back(y[0]);
	ll ans = 0;
	for (int i = 0; i < n; i++) ans += 1LL * (y[i] + y[i + 1]) * (x[i] - x[i + 1]);
	printf("%lld\n", abs(ans));
}

