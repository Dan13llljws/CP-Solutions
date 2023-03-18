#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int &v : a) cin >> v;
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0, j = n - 1; i <= j;){
		if (a[j] + a[i] > x)  j--;
		else i++, j--;
		ans++;
	}
	cout << ans << '\n';
}
