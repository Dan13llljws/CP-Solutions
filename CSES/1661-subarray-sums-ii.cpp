#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, x;
	cin >> n >> x;
	map<long long,int> mp;
	long long sum = 0, ans = 0;
	mp[0] = 1;
	while(n--){
		int a;
		cin >> a;
		sum += a;
		ans += mp[sum - x];
		mp[sum]++;
	}
	cout << ans << '\n';
}

