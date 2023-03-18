#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	while(n--){
		int a, b;
		cin >> a >> b;
		int ans = 1;
		while(b){
			if (b & 1) 
				ans = 1LL * ans * a % mod;
			a = 1LL * a * a % mod;
			b >>= 1;
		}
		cout << ans << '\n';
	}
}
