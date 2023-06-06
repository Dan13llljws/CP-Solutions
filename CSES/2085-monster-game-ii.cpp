#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};
struct LineContainer : multiset<Line, less<>> {
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
int main(){
    int n, x;
    cin >> n >> x;
    vector<int> s(n), f(n);
    for (int &x : s) cin >> x;
    for (int &x : f) cin >> x;
    vector<ll> dp(n);
    LineContainer lc;
    lc.add(-x, 0);
    for (int i = 0; i < n; i++){ 
        dp[i] = lc.query(s[i]);
        lc.add(-f[i], dp[i]);
    }
    cout << -dp[n - 1] << '\n';
}

