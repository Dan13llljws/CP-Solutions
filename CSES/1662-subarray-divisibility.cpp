#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	map<int,int> mp;
	long long sum = 0, ans = 0;
	mp[0] = 1;
	for (int i = 0; i < n; i++){
		int a;
		cin >> a;
		sum += a % n;
		if (sum >= n) sum -= n;
		if (sum < 0) sum += n;
		ans += mp[sum];
		mp[sum]++;
	}
	cout << ans << '\n';
}


