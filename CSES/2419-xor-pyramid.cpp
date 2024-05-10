#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	int ans = 0, num = 0, den = 0;
	vector<int> t(n);
	for (int i = 1; i < n; i++) {
		t[i] = __builtin_ctz(i), num += t[i], den += t[i]; 
	}
	for (int i = 0; i < n; i++) {
		if (num == den) ans ^= a[i];	
		if (i < n - 1) den += t[i + 1] - t[n - 1 - i];
	}
	cout << ans << '\n';
}
