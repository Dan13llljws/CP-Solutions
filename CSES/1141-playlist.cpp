#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	map<int,int> f;
	int ans = 0;
	for (int l = 0, r = 0; r < n; r++){
		f[a[r]]++;
		while(f[a[r]] == 2) f[a[l++]]--;
		ans = max(ans, r - l + 1);
	}
	cout << ans << '\n';
}
