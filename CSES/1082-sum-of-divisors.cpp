#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long n;
	cin >> n;
    long long ans = 0;
    for (long long i = n, j = 1; i; ){
        long long nxti = n / (j + 1);
        long long a = i - nxti;
        long long b = i + nxti + 1;
        if (a % 2) b >>= 1;
        else a >>= 1;
        ans = (ans + a % mod * (b % mod) % mod * j) % mod;
        if (i == 1) break;
        j = n / nxti;
        i = nxti;
    }
    cout << ans << '\n';
}
