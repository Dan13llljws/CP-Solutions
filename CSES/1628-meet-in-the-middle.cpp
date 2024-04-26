#include <bits/stdc++.h>
using namespace std;
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	int l = n / 2, r = n - l;
	unordered_map<long long,int, custom_hash> freq;
	for (int msk = 0; msk < (1 << l); msk++){
			long long sum = 0;
			for (int i = 0; i < l; i++)
					if (msk >> i & 1) sum += a[i];
			if (sum <= x) freq[sum]++;
	}
	long long ans = 0;
	for (int msk = 0; msk < (1 << r); msk++){
			long long sum = 0;
			for (int i = 0; i < r; i++)
					if (msk >> i & 1) sum += a[i + l];
			if (sum <= x && freq.count(x - sum)) ans += freq[x - sum];
	}
	cout << ans << '\n';
}

