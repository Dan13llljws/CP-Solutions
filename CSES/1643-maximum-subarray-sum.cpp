#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	long long mn = 0, sum = 0, mx = -1e18;
	while(n--){
		int a;
		cin >> a;
		sum += a;
		mx = max(mx, sum - mn);
		mn = min(mn, sum);
	}
	cout << mx << '\n';
}
