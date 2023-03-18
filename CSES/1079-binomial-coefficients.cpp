#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, MM = 1e6 + 5;
vector<int> fac(MM), inv(MM);
int fpow(int a, int b){
	int ret = 1;
	while(b){
		if (b & 1)
			ret = 1LL * ret * a % mod;
		a = 1LL * a * a % mod;
		b >>= 1;
	}
	return ret;
}
int choose(int a, int b){
	return 1LL * fac[a] * inv[b] % mod * inv[a - b] % mod;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= 1e6; i++) fac[i] = 1LL * fac[i - 1] * i % mod;
	inv[1e6] = fpow(fac[1e6], mod - 2);
	for (int i = 1e6 - 1; i; i--) inv[i] = 1LL * inv[i + 1] * (i + 1) % mod;
	while(n--){
		int a, b;
		cin >> a >> b;
		cout << choose(a, b) << '\n';
	}
}
