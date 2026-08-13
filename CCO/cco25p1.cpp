#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; ll M; cin >> n >> M;
	map<ll,vector<ll>> f;
	for (int i = 0; i < n; i++) {
		ll v, m; cin >> v >> m;
		f[m].push_back(v);
	}
	f.emplace(1e18, vector<ll>{});
	ll ans = 0;
	for (auto it = f.begin();;) {
		auto &[m, v] = *it;
		++it;
		if (it == f.end()) break;
		ranges::sort(v);
		auto &[nm, nv] = *it;
		ll rem = M % nm;
		while(rem >= m && v.size()) {
			M -= m;
			rem -= m;
			ans += v.back();
			v.pop_back();
		}
		ll d = nm / m, s = 0;
		ranges::reverse(v);
		for (int i = 0; i < v.size(); i++) {
			s += v[i];
			if ((i + 1) % d == 0) {
				nv.push_back(s);
				s = 0;
			}
		}
		if (s) nv.push_back(s);
	}
	cout << ans << '\n';
}