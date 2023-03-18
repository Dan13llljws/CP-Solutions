#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, t;
	cin >> n >> t;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	long long l = 0, r = 2e18 / n;
	while(l < r){
		long long mid = l + (r - l) / 2;
		long long cnt = 0;
		for (int i = 0; i < n; i++) cnt += mid / a[i];
		if (cnt >= t) r = mid;
		else l = mid + 1;
	}
	cout << l << '\n';
}

