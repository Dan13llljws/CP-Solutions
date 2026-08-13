#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	ll k; cin >> k;
	vector<ll> cnt;
	vector<char> c;
	ll cur = 0; char ch;
	for (char x : s) {
		if (isalpha(x)) {
			if (cur) cnt.push_back((cnt.size() ? cnt.back() : 0) + cur), c.push_back(ch);
			ch = x, cur = 0;
		} else cur = cur * 10 + (x - '0');
	}
	cnt.push_back((cnt.size() ? cnt.back() : 0) + cur), c.push_back(ch);
	int i = upper_bound(cnt.begin(), cnt.end(), k % cnt.back()) - cnt.begin();
	cout << c[i] << '\n';
}