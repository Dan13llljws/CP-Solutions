#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<int M1, int M2>
class Hash {
public:
	int x, y;
	Hash() = default;
	Hash(int _x): x((_x + M1) % M1), y((_x + M2) % M2) {}
	Hash(int _x, int _y): x((_x + M1) % M1), y((_y + M2) % M2) {}
	inline Hash operator+(const Hash &h) const { return Hash((x + h.x) % M1, (y + h.y) % M2); }
	inline Hash operator-(const Hash &h) const { return Hash((x - h.x + M1) % M1, (y - h.y + M2) % M2); }
	inline Hash operator*(const Hash &h) const { return Hash(1LL * x * h.x % M1, 1LL * y * h.y % M2); }
	inline bool operator==(const Hash &h) const { return x == h.x && y == h.y; }
};
using H = Hash<1000000007, 1000000009>;
const int base = 13331;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;
	string s; cin >> s;
	vector<H> bit(n + 1), bit_rev(n + 1);
	auto upd = [&](int x, H v, vector<H> &bit) -> void {
		for (; x <= n; x += x & -x) bit[x] = bit[x] + v;
	};
	auto qry = [&](int x, const vector<H> &bit) -> H {
		H ret(0);
		for (; x; x -= x & -x) ret = ret + bit[x];
		return ret;
	};
	auto get = [&](int l, int r, const vector<H> &bit) -> H { 
		return qry(r, bit) - qry(l - 1, bit);
	};
	vector<H> p(n + 1);
	p[0] = H(1);
	for (int i = 1; i <= n; i++) p[i] = p[i - 1] * base;
	for (int i = 0; i < n; i++) {
		upd(i + 1, p[i] * s[i], bit);
		upd(n - i, p[n - i - 1] * s[i], bit_rev);
	}
	while(m--) {
		int t; cin >> t;
		if (t == 1) {
			int k; char c; cin >> k >> c;
			upd(k, p[k - 1] * (c - s[k - 1]), bit);
			upd(n - k + 1, p[n - k] * (c - s[k - 1]), bit_rev);
			s[k - 1] = c;
		} else {
			int l, r; cin >> l >> r;
			H h = get(l, r, bit) * p[n - r + 1], h_rev = get(n - r + 1, n - l + 1, bit_rev) * p[l];
			cout << (h == h_rev ? "YES" : "NO") << '\n';
		}
	}
}
