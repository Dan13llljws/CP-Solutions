#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int &x : a) cin >> x;
	for (int &x : b) cin >> x;
	vector<int> id(n);
	iota(id.begin(), id.end(), 0);
	vector<vector<char>> ans(n, vector<char>(n, '.'));
	if (accumulate(a.begin(), a.end(), 0) != accumulate(b.begin(), b.end(), 0))
		return cout << -1 << '\n', 0;
	for (int i = 0; i < n; i++) {
		sort(id.begin(), id.end(), [&](int j, int k) {
			return a[j] > a[k];
		});
		for (int j = 0; j < b[i]; j++) {
			int k = id[j];
			if (!a[k]) return cout << -1 << '\n', 0;
			a[k]--, ans[k][i] = 'X';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			cout << ans[i][j];
		cout << '\n';
	}
}
