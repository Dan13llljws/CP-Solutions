#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int &x : a) cin >> x;
	for (int &x : b) cin >> x;
	vector<vector<int>> f(n + 1);
	for (int i = 0; i < n; i++) f[b[i]].push_back(i);
	for (auto &v : f) reverse(v.begin(), v.end());
	vector<int> c(n), d(n);
	set<pair<int,int>> st;
	int t = 0;
	for (int i = n - 1; i >= 0; i--) {
		int x = a[i];
		if (f[x].empty()) return cout << -1 << '\n', 0;
		int p = f[x].back(); f[x].pop_back();
		auto it = st.upper_bound({-p, 0});
		if (it == st.end()) {
			c[i] = d[p] = ++t;
			st.insert({-p, t});
		} else {
			c[i] = d[p] = it->second;
			st.erase(it);
			st.insert({-p, c[i]});
		}
	}
	cout << *max_element(c.begin(), c.end()) << '\n';
	for (int x : c) cout << x << ' ';
	cout << '\n';
	for (int x : d) cout << x << ' ';
	cout << '\n';
}
