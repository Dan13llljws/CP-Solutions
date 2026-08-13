#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N; cin >> N;
	vector<ll> c(N + 1), even, odd;
	for (int i = 1; i <= N; i++) {
		cin >> c[i];
		if (c[i] & 1) odd.push_back(i);
		else even.push_back(i);
	}
	if (c[1] != -1) {
		if (even.size() > 1) {
			cout << "YES\n1 1\n" << even[0] << '\n' << even[1] << '\n';
		} else if (even.size() == 1) {
			if (odd.size() > 1) {
				cout << "YES\n1 2\n" << even[0] << '\n' << odd[0] << ' ' << odd[1] << '\n';
			} else {
				ll a = even[0], b = odd[0];
				if (gcd(c[a], c[b]) == 1) cout << "NO\n";
				else cout << "YES\n1 1\n" << a << '\n' << b << '\n';
			}
		} else {
			if (odd.size() > 3) {
				cout << "YES\n2 2\n" << odd[0] << ' ' << odd[1] << '\n' << odd[2] << ' ' << odd[3] << '\n';
			} else if (odd.size() == 3) {
				ll a = c[odd[0]], b = c[odd[1]], d = c[odd[2]];
				if (gcd(a + b, d) != 1) cout << "YES\n2 1\n" << odd[0] << ' ' << odd[1] << '\n' << odd[2] << '\n';
				else if (gcd(a + d, b) != 1) cout << "YES\n2 1\n" << odd[0] << ' ' << odd[2] << '\n' << odd[1] << '\n';
				else if (gcd(d + b, a) != 1) cout << "YES\n2 1\n" << odd[2] << ' ' << odd[1] << '\n' << odd[0] << '\n';
				else cout << "NO\n";
			} else {
				ll a = odd[0], b = odd[1];
				if (gcd(c[a], c[b]) == 1) cout << "NO\n";
				else cout << "YES\n1 1\n" << a << '\n' << b << '\n';
			}
		}
	} else {
		int k = min(100, N / 4);
		cout << k << '\n';
		mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
		auto idx = views::iota(0, N) | ranges::to<vector<int>>() ;
		ranges::shuffle(idx, rng);
		for (int i = 0; i < k; i++) {
			cout << 2 << ' ' << 2 << '\n' << idx[4 * i] << ' ' << idx[4 * i + 1] << '\n' << idx[4 * i + 2] << ' ' << idx[4 * i + 3] << '\n';
		}
	}
}