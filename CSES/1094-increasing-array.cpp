#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x; 
	long long ans = 0;
	for (int i = 1; i < n; i++){
		ans += max(0, a[i - 1] - a[i]);
		a[i] = max(a[i], a[i - 1]);
	}
	cout << ans << '\n';
}
