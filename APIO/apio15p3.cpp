#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// dynamically solve the optmization problem \min_x \sum_{i=1}^n |x_i-x|
class SlidingMedian {
	int64_t suml, sumr;
	multiset<int> l, r;
public:
	SlidingMedian(): suml{0}, sumr{0}, l{}, r{} {}
	void add(int x) {
		if (l.empty() || x <= mid()) l.insert(x), suml += x;
		else r.insert(x), sumr += x;
		normalize();
	}
	void rem(int x) {
		auto it = l.find(x);
		if (it != l.end()) suml -= x, l.erase(it);
		else r.erase(r.find(x)), sumr -= x;
		normalize();
	}
	int mid() { return *l.rbegin(); }
	int64_t opt() {
		if (l.empty()) return 0;
		int x = mid();
		return (1LL * x * l.size() - suml) + (sumr - 1LL * x * r.size());
	}
private:
	void normalize() {
		if (l.size() > r.size() + 1) {
			int x = mid();
			suml -= x, sumr += x;
			l.erase(prev(l.end())), r.insert(x);
		} else if (r.size() > l.size()) {
			int x = *r.begin();
			suml += x, sumr -= x;
			l.insert(x), r.erase(r.begin());
		}
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int k, n; cin >> k >> n;
	vector<pair<int,int>> p;
	vector<int> xs;
	ll base_cost = 0;
	for (int i = 0; i < n; i++) {
		char a, b; int l, r; cin >> a >> l >> b >> r;
		if (l > r) swap(l, r);
		if (a == b) { base_cost += r - l; continue; }
		base_cost++;
		p.emplace_back(l, r);
		xs.push_back(l), xs.push_back(r);
	}
	ranges::sort(p, less<int>(), [](auto &&x) { return x.first + x.second; });
	SlidingMedian sm1, sm2;
	for (int x : xs) sm1.add(x);
	ll ans = base_cost + sm1.opt();
	if (k == 1) return cout << ans << '\n', 0;
	for (auto [l, r] : p) {
		sm1.rem(l), sm1.rem(r);
		sm2.add(l), sm2.add(r);
		ans = min(ans, base_cost + sm1.opt() + sm2.opt());
	}
	cout << ans << '\n';
}