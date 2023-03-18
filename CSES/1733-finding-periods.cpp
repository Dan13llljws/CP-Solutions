#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, base = 131;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	vector<long long> h(n + 2), p(n + 2);
	p[0] = 1;
	for (int i = 1; i <= n; i++){
		p[i] = p[i - 1] * base % mod;
		h[i] = (h[i - 1] * base + s[i - 1]) % mod;
	}
	auto get = [&](int l, int r){
		return (h[r] - h[l - 1] * p[r - l + 1] % mod + mod) % mod;
	};
	for (int i = 1; i <= n; i++){
		bool f = 1;
		for (int j = 1; j + i - 1 <= n; j += i)
			if (get(1, i) != get(j, j + i - 1)) f = 0;
		if (n % i && get(1, n % i) != get(n / i * i + 1, n)) f = 0;
		if (f) cout << i << ' ';
	}
}			


