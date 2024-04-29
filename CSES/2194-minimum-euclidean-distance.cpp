#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int n;
vector<pair<ll,ll>> p;
ll ans = 8e18;
#define x first
#define y second
 
ll dist(pair<ll,ll> a, pair<ll,ll> b) {
	return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}
 
void rec(int l, int r) {
	if (l == r - 1) return;
	int mid = (l + r) >> 1;
	ll mx = p[mid].x;
	rec(l, mid); rec(mid, r);
	vector<pair<ll,ll>> tmp(r - l);
	merge(p.begin() + l, p.begin() + mid, p.begin() + mid, p.begin() + r, tmp.begin(),
		[&](auto a, auto b) { return a.y < b.y; });
	copy(tmp.begin(), tmp.end(), p.begin() + l);
	for (int i = l, j = 0; i < r; i++) {
		if ((p[i].x - mx) * (p[i].x - mx) >= ans) continue;
		for (int k = j - 1; k >= 0 && (p[i].y - tmp[k].y) * (p[i].y - tmp[k].y) < ans; k--) 
			ans = min(ans, dist(p[i], tmp[k]));
		tmp[j++] = p[i];
	}
}
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n; p.resize(n);
	for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
	sort(p.begin(), p.end());
	rec(0, n); 
	cout << ans << '\n';
}
