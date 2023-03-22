#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
ll fpow(ll x, int k){
    ll ret = 1;
    while(k){
        if (k & 1) ret = ret * x % MOD;
        x = x * x % MOD, k >>= 1;
    } return ret;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if (n & 1){
        cout << 0 << '\n';
        return 0;
    }
    vector<ll> fac(n + 1), inv(n + 1);
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
    inv[n] = fpow(fac[n], MOD - 2);
    for (int i = n - 1; i; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
    auto C = [&](int a, int b){
        return fac[a] * inv[b] % MOD * inv[a - b] % MOD;
    };
    cout << C(n, n / 2) * fpow(n / 2 + 1, MOD - 2) % MOD << '\n';
}
