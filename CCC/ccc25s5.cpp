#include "bits/stdc++.h"
using namespace std;

using ll = long long;
const int mod = 1e6 + 3;

#define lc i << 1
#define rc i << 1 | 1

struct {
	ll s, t;
} seg[mod << 2];

void update(int i, int s, int t, int l, int r) {
	if (l == r - 1) {
		seg[i].s = s, seg[i].t += t;
		return;
	}
	int m = (l + r) >> 1;
	if (s < m) update(lc, s, t, l, m);
	else update(rc, s, t, m, r);
	seg[i].t = seg[lc].t + seg[rc].t;
	seg[i].s = max(seg[lc].s, seg[rc].s - seg[lc].t);
	if (!seg[lc].t) seg[i].s = seg[rc].s;
	else if (!seg[rc].t) seg[i].s = seg[lc].s;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int q; cin >> q; 
	ll ans = 0;

	vector<pair<int,int>> homeworks;
	homeworks.reserve(q);
	int s, t, i;
	while(q--) {
		char type; cin >> type;
		if (type == 'A') {
			cin >> s >> t;
			s = (s + ans) % mod;
			t = (t + ans) % mod;
			s--;
			homeworks.emplace_back(s, t);
			update(1, s, t, 0, mod);
		} else {
			cin >> i; i--;
			i = (i + ans) % mod;
			auto [s, t] = homeworks[i];
			update(1, s, -t, 0, mod);
		}
		ans = seg[1].s + seg[1].t;
		cout << ans << endl;
	}
}