#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	long long sum = 0, mx = 0;
	while(n--){
		int a;
		cin >> a;
		sum += a;
		mx = max(mx, 1LL * a);
	}
	cout << max(2 * mx, sum) << '\n';
}
