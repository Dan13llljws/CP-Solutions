#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	sort(a.begin(), a.end());
	long long ans = 0;
	for (int x : a) ans += abs(x - a[n / 2]);
	cout << ans << '\n';
}
