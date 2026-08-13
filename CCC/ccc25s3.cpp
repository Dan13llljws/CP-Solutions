#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, q; cin >> n >> m >> q;
	vector<multiset<int, greater<int>>> f(m);
	multiset<int, greater<int>> ngmi;
	vector<int> c(n), p(n);
	ll sum = 0;
	multiset<int> mxs;

	auto remove = [&](int i) {
		auto &fc = f[c[i]];
		int old_mx = *fc.begin();
		fc.erase(fc.lower_bound(p[i]));
		int new_mx = fc.size() ? *fc.begin() : 0;
		sum -= old_mx - new_mx;
		mxs.erase(mxs.lower_bound(old_mx));
		if (new_mx) mxs.insert(new_mx);
		if (new_mx) ngmi.erase(ngmi.lower_bound(min(new_mx, p[i])));
	};

	auto add = [&](int i) {
		auto &fc = f[c[i]];
		int old_mx = fc.size() ? *fc.begin() : 0;
		fc.insert(p[i]);
		int new_mx = *fc.begin();
		sum -= old_mx - new_mx;
		if (old_mx) mxs.erase(mxs.lower_bound(old_mx));
		mxs.insert(new_mx);
		if (old_mx) ngmi.insert(min(old_mx, p[i]));
	};

	for (int i = 0; i < n; i++) {
		cin >> c[i] >> p[i]; c[i]--;
		add(i);
	}
	auto print = [&]() {
		if (ngmi.empty()) cout << sum << '\n';
		else cout << sum + max(0, *ngmi.begin() - *mxs.begin()) << '\n';	
	};
	print();

	while(q--) {
		int t, i, x; cin >> t >> i >> x; i--;
		remove(i);
		if (t == 1) c[i] = --x;
		else p[i] = x;
		add(i);
		print();
	}
}