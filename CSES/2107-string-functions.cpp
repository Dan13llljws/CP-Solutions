#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	int n = s.size();
	vector<int> z(n), f(n);
	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i < r) z[i] = min(z[i - l], r - i);
		while(i + z[i] < n && s[i + z[i]] == s[z[i]]) z[i]++;
		if (i + z[i] > r) l = i, r = i + z[i];
	}
	for (int i = 1, j = 0; i < n; i++) {
		while(j && s[j] != s[i]) j = f[j - 1];
		if (s[j] == s[i]) j++;
		f[i] = j;
	}
	for (int x : z) cout << x << ' ';
	cout << '\n';
	for (int x : f) cout << x << ' ';
	cout << '\n';
}
