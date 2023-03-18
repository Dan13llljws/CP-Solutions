#include <bits/stdc++.h>
using namespace std;
int fpow(int a, int b, int mod){
	int ret = 1;
	while(b){
		if (b & 1)
			ret = 1LL * ret * a % mod;
		a = 1LL * a * a % mod;
		b >>= 1;
	}
	return ret;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	while(n--){
		int a, b, c;
		cin >> a >> b >> c;
		cout << fpow(a, fpow(b, c, 1e9 + 6), 1e9 + 7) << '\n';
	}
}
