#include <bits/stdc++.h>
using namespace std;
 
template<class T, int ALPH=256>
class SuffixArray {
	T s; int n;
	vector<int> p, c, cnt;
public:
	SuffixArray(const T &_s): s(_s), n(s.size() + 1), p(n), c(n), cnt(max(ALPH, n)) {
		s.push_back(0);
		for (int i = 0; i < n; i++) cnt[s[i]]++;
		for (int i = 1; i < ALPH; i++) cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; i--) p[--cnt[s[i]]] = i;
		for (int i = 1; i < n; i++) c[p[i]] = c[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);
		vector<int> pn(n), cn(n);
		for (int h = 0, cls = c[p[n - 1]]; cls < n - 1; h++, cls = c[p[n - 1]]) {
			for (int i = 0; i < n; i++) {
				pn[i] = p[i] - (1 << h);
				if (pn[i] < 0) pn[i] += n;
			}
			fill(cnt.begin(), cnt.end(), 0);
			for (int i = 0; i < n; i++) cnt[c[pn[i]]]++;
			for (int i = 1; i <= cls; i++) cnt[i] += cnt[i - 1];
			for (int i = n - 1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];
			cn[p[0]] = 0;
			for (int i = 1; i < n; i++) {
				pair<int,int> cur{c[p[i]], c[(p[i] + (1 << h)) % n]};
				pair<int,int> prev{c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
				cn[p[i]] = cn[p[i - 1]] + (cur != prev);
			}
			c = cn;
		}
	}
	int lower_bound(const T &t) const {
		int l = 0, r = n, k = t.size();
		while(l < r) {
			int mid = (l + r) >> 1;
			if (s.compare(p[mid], min(n - p[mid], k), t) >= 0) r = mid;
			else l = mid + 1;
		}
		return l;
	}
	int upper_bound(const T &t) const {
		int l = 0, r = n, k = t.size();
		while(l < r) {
			int mid = (l + r) >> 1;
			if (s.compare(p[mid], min(n - p[mid], k), t) > 0) r = mid;
			else l = mid + 1;
		}
		return l;
	}
	int count(const T &t) const { return upper_bound(t) - lower_bound(t); }
	vector<int> get_p() const { return p; }
	vector<int> get_lcp() const {
		vector<int> rank(n);
		for (int i = 0; i < n; i++) rank[p[i]] = i;
		vector<int> lcp(n - 1);
		for (int i = 0, k = 0; i < n; i++) {
			if (rank[i] == n - 1) { k = 0; continue; }
			int j = p[rank[i] + 1];
			while(i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
			lcp[rank[i]] = k;
			if (k) k--;
		}
		return lcp;
	}
};
 
long long n_diff_substr(const vector<int> &lcp) { // non-empty
	int n = lcp.size();
	return 1LL * n * (n + 1) / 2 - accumulate(lcp.begin(), lcp.end(), 0LL);
}
 
int main() {
	string s; cin >> s;
	SuffixArray<string> sa(s);
	auto p = sa.get_p();
	auto lcp = sa.get_lcp();
	int mx = 0, idx = -1;
	for (int i = 0; i < (int)lcp.size(); i++) 
		if (mx < lcp[i]) mx = lcp[i], idx = p[i];
	if (mx == 0) cout << -1 << '\n';
	else cout << s.substr(idx, mx) << '\n';
}
