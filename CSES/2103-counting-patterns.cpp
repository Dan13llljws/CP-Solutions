#include <bits/stdc++.h>
using namespace std;
 
template<class T, int ALPH=256>
class SuffixArray {
	T s; int n;
	vector<int> p, c, cnt;
	int lower_bound(T &t) {
		int l = 0, r = n;
		while(l < r) {
			int mid = (l + r) >> 1;
			bool geq = 1;
			for (int i = 0; i < (int)t.size(); i++) {
				if (s[p[mid] + i] < t[i]) geq = 0;
				if (s[p[mid] + i] != t[i]) break;
			}
			if (geq) r = mid;
			else l = mid + 1;
		}	
		return l;
	}
	int upper_bound(T &t) {
		int l = 0, r = n;
		while(l < r) {
			int mid = (l + r) >> 1;
			bool ge = 0;
			for (int i = 0; i < (int)t.size(); i++) {
				if (s[p[mid] + i] > t[i]) ge = 1;
				if (s[p[mid] + i] != t[i]) break;
			}
			if (ge) r = mid;
			else l = mid + 1;
		}	
		return l;
	}
public:
	SuffixArray(T &_s): s(_s), n(s.size() + 1), p(n), c(n), cnt(max(ALPH, n)) {
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
	vector<int> get_SA() { return p; }
	int count(T &t) { return upper_bound(t) - lower_bound(t); }
};
 
int main() {
	string s; cin >> s;
	SuffixArray<string> sa(s);	
	int q; cin >> q;
	while(q--) {
		string t; cin >> t;
		cout << sa.count(t) << '\n';
	}
}
