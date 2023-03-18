#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	long long ans = 1e9;
	for (int mask = 0; mask < (1 << n); mask++){
		long long s1 = 0, s2 = 0;
		for (int i = 0; i < n; i++)
			if (mask >> i & 1) s1 += a[i];
			else s2 += a[i];
		ans = min(ans, abs(s1 - s2));
	}
	cout << ans << '\n';
}
