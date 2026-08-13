#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; ll k; cin >> n >> k;
	vector<int> a(n);

	ranges::for_each(a, [](auto &x) { cin >> x; });
	auto c = a;
	ranges::sort(c);
	c.erase(ranges::unique(c).begin(), c.end());
	int t = c.size();

	vector<int> bit(t + 1);
	auto upd = [&](int x) {
		for (; x <= t; x += x & -x) bit[x] += 1;
	};
	auto get = [&](int x) {
		int ret = 0;
		for (; x; x -= x & -x) ret += bit[x];
		return ret;
	};

	vector<int> less_after(n), zpsa(n + 1);
	for (auto &&[i, x] : a | views::enumerate | views::reverse) {
		zpsa[i] = zpsa[i + 1] + (x == 0);
		if (x) {
			int j = ranges::lower_bound(c, x) - c.begin();
			less_after[i] = get(j);
			upd(j + 1);
		}
	}

	cout << *ranges::lower_bound(views::iota(0, n), true, less<bool>{}, [&](auto mid) -> bool {
		int m = zpsa[0];
		vector<int> need(m);
		for (auto &&[i, x] : a | views::enumerate) {
			if (x == 0) continue;
			if (less_after[i] > mid) return false;
			int rem = mid - less_after[i];
			int pos = m - (zpsa[i] - rem);
			if (pos < m) need[pos] = max(need[pos], x);
		}
		ll ans = 0;
		if (m) ans += need[0];
		for (int i = 1; i < m; i++) ans += need[i] = max(need[i], need[i - 1]);
		return ans <= k;
	}) << '\n';
}