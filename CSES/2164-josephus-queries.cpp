#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int q; cin >> q;
	while(q--) {
		int n, k; cin >> n >> k;
		int ans = 0;
		int c1 = n / 2, c0 = n - c1, s = 1;
		for (int i = 0; i < 30; i++) {
			if (s == 1) {
				if (c1 == 0) break;
				if (k > c1) {
					int d1 = c0 / 2, d0 = c0 - d1;
					k -= c1, s = c0 == c1, c0 = d0, c1 = d1;
				} else {
					ans |= (1 << i) | ((k - 1) << (i + 1));
					break;
				}
			} else {
				ans |= (1 << i);
				if (c0 == 0) break;
				if (k > c0) {
					int d1 = c1 / 2, d0 = c1 - d1;
					k -= c0, s = c0 != c1, c0 = d0, c1 = d1;
				} else {
					ans |= ((k - 1) << (i + 1));
					ans ^= (1 << i);
					break;
				}
			}
		}
		cout << ans + 1 << '\n';
	}
}
