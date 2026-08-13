#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
	ll a, b, k; int t; cin >> a >> b >> k >> t;
	ll d = abs(a - b);
	ll f = d / k + d % k, g = d / k + 1 + (k - d % k);
	if (t == 1) {
		cout << min(f, g) << '\n';
	} else {
		if (k == 2 && d > 1) cout << min(f, g) + 1 << '\n';
		else {
			ll x = f == g ? LLONG_MAX : max(f, g);
			cout << min(x, min(f, g) + 2) << '\n';
		}
	}
}